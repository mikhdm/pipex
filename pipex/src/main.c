/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:01:08 by rmander           #+#    #+#             */
/*   Updated: 2021/07/28 00:24:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include "error.h"
#include "environ.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

/* static void	rightchild(t_meta *meta, int pfds[2], int ofd) */
/* { */
/* 	close(pfds[1]); */
/* 	dup2(pfds[0], STDIN_FILENO); */
/* 	close(pfds[0]); */
/* 	ofd = open(meta->out, (O_WRONLY | O_CREAT), (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)); */
/* 	dup2(ofd, STDOUT_FILENO); */
/* 	close(ofd); */
/* } */

/* static void	leftchild(t_meta *meta, int pfds[2], int ifd) */
/* { */
/* 	if (close(pfds[0]) == -1) */
/* 		pexitfree(ERR_ERRNO, errno, meta, NULL); */

/* 	if (dup2(pfds[1], STDOUT_FILENO) == -1) */
/* 		pexitfree(ERR_ERRNO, errno, meta, NULL); */

/* 	if (close(pfds[1]) == -1) */
/* 		pexitfree(ERR_ERRNO, errno, meta, NULL); */

/* 	ifd = open(meta->in, O_RDONLY); */
/* 	if (ifd == -1) */
/* 		pexitfree(ERR_ERRNO, errno, meta, NULL); */

/* 	if (dup2(ifd, STDIN_FILENO) == -1) */
/* 		pexitfree(ERR_ERRNO, errno, meta, NULL); */

/* 	close(ifd); */
/* } */

/* static void pipex(t_meta *meta) */
/* { */
/* 	int			i; */

/* 	i = 0; */
/* 	while (i < 2) */
/* 	{ */
/* 		pids[i] = fork(); */
/* 		if (pids[i] == -1) */
/* 			pexitfree(ERR_ERRNO, errno, meta, NULL); */
/* 		else if (pids[i] == 0) */
/* 		{ */
/* 			if (i == 0) */
/* 				leftchild(meta, pfds, ifd); */
/* 			else if (i == 1) */
/* 				rightchild(meta, pfds, ofd); */

/* 			execve(bin_path(meta), argv, meta->envp); */
/* 			pexitfree(ERR_ERRNO, errno, meta, NULL); */
/* 		} */
/* 		else */
/* 			i++; */
/* 	} */
/* 	close(pfds[0]); */
/* 	close(pfds[1]); */
/* 	i = 0; */
/* 	while (i < 2) */
/* 		waitpid(pids[i++], NULL, 0); */
/* } */

int		main(int argc, char **argv, char **envp)
{
	t_meta		*meta;

	if (argc != 5)
		pexit(ERR_ARGS_WRONG, 255, argv[0]);
	meta = NULL;
	if (!alloca_to((void **)&meta, sizeof(t_meta)))
		pexit(ERR_ERRNO, errno, argv[0]);
	init(meta);
	setup(meta, argv, envp);
	cleanup(meta, NULL);
	/* pipex(meta); */
	return (0);
}
