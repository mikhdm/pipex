/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:01:08 by rmander           #+#    #+#             */
/*   Updated: 2021/07/28 22:19:03 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include "error.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

static void	rightchild(t_meta *meta)
{
	if (close(meta->pfds[1]) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	meta->pfds[1] = -1;
	if (dup2(meta->pfds[0], STDIN_FILENO) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	if (close(meta->pfds[0]) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	meta->pfds[0] = -1;
	meta->ofd = open(meta->out, (O_WRONLY | O_CREAT | O_TRUNC),
					 (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
	if (meta->ofd == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	if (dup2(meta->ofd, STDOUT_FILENO) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	if (close(meta->ofd) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	meta->ofd = -1;
}

static void	leftchild(t_meta *meta)
{
	if (close(meta->pfds[0]) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	meta->pfds[0] = -1;
	if (dup2(meta->pfds[1], STDOUT_FILENO) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	if (close(meta->pfds[1]) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	meta->pfds[1] = -1;
	meta->ifd = open(meta->in, O_RDONLY);
	if (meta->ifd == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	if (dup2(meta->ifd, STDIN_FILENO) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	if (close(meta->ifd) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	meta->ifd = -1;
}

static void pipex(t_meta *meta)
{
	int		i;
	char	*program;

	i = 0;
	program = NULL;
	if (pipe(meta->pfds) == -1)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
	while (i < 2)
	{
		meta->pids[i] = fork();
		if (meta->pids[i] == -1)
			pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
		else if (meta->pids[i] == 0)
		{
			if (i == 0)
				leftchild(meta);
			else if (i == 1)
				rightchild(meta);
			program = bin(meta, meta->cmd[i][0]);
			execve(program, meta->cmd[i], meta->envp);
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
