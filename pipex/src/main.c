/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:01:08 by rmander           #+#    #+#             */
/*   Updated: 2021/07/29 03:18:54 by mikhaylen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include "error.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

static int	rightchild(t_meta *meta)
{
	if (close(meta->pfds[1]) == -1)
		return (EXIT_FAILURE);
	meta->pfds[1] = -1;
	if (dup2(meta->pfds[0], STDIN_FILENO) == -1)
		return (EXIT_FAILURE);
	if (close(meta->pfds[0]) == -1)
		return (EXIT_FAILURE);
	meta->pfds[0] = -1;
	meta->ofd = open(meta->out, (O_WRONLY | O_CREAT | O_TRUNC),
					 (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
	if (meta->ofd == -1)
		return (EXIT_FAILURE);
	if (dup2(meta->ofd, STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	if (close(meta->ofd) == -1)
		return (EXIT_FAILURE);
	meta->ofd = -1;
	return (EXIT_SUCCESS);
}

static int leftchild(t_meta *meta)
{
	if (close(meta->pfds[0]) == -1)
		return (EXIT_FAILURE);
	meta->pfds[0] = -1;
	if (dup2(meta->pfds[1], STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	if (close(meta->pfds[1]) == -1)
		return (EXIT_FAILURE);
	meta->pfds[1] = -1;
	meta->ifd = open(meta->in, O_RDONLY);
	if (meta->ifd == -1)
		return (EXIT_FAILURE);
	if (dup2(meta->ifd, STDIN_FILENO) == -1)
		return (EXIT_FAILURE);
	if (close(meta->ifd) == -1)
		return (EXIT_FAILURE);
	meta->ifd = -1;
	return (EXIT_SUCCESS);
}

static void pipex(t_meta *meta)
{
	int		i;
	int		status;
	char	*program;

	i = 0;
	program = NULL;
	status = EXIT_SUCCESS;
	if (pipe(meta->pfds) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	while (i < 2)
	{
		meta->pids[i] = fork();
		if (meta->pids[i] == -1)
			pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
		else if (meta->pids[i] == 0)
		{
			program = bin(meta, meta->cmd[i][0]);
			if (!program)
				pexitfree(ERR_CMD_NOT_FOUND, EXIT_FAILURE, meta, NULL);
			if (i == 0)
				status = leftchild(meta);
			else if (i == 1)
				status = rightchild(meta);
			if (status == EXIT_FAILURE)
				pexitfree(ERR_ERRNO, status, meta, program);
			if (execve(program, meta->cmd[i], meta->envp) == -1)
				pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, program);
		}
		else
			++i;
	}
	i = 0;
	if (close(meta->pfds[0]) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	meta->pfds[0] = -1;
	if (close(meta->pfds[1]) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	meta->pfds[1] = -1;
	while (i < 2)
	{
		if (waitpid(meta->pids[i], NULL, 0) == -1)
			pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
		++i;
	}
}

int		main(int argc, char **argv, char **envp)
{
	t_meta		*meta;

	if (argc != 5)
		pexit(ERR_ARGS_WRONG, 255, argv[0]);
	meta = NULL;
	if (!alloca_to((void **)&meta, sizeof(t_meta)))
		pexit(ERR_ERRNO, EXIT_FAILURE, argv[0]);
	init(meta);
	setup(meta, argv, envp);
	pipex(meta);
	cleanup(meta, NULL);
	return (EXIT_SUCCESS);
}
