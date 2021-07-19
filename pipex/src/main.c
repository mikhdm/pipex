/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:01:08 by rmander           #+#    #+#             */
/*   Updated: 2021/07/19 23:16:37 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include "error.h"
#include "environ.h"
#include <errno.h>

static void	init(t_meta *meta)
{
	meta->title = NULL;
	meta->env = NULL;
	meta->in = NULL;
	meta->out = NULL;
	meta->dirs = NULL;
}

int		main(int argc, char **argv, char **envp)
{
	t_meta		*meta;

	if (argc < 5)
		pexit(ERR_ARGS_WRONG, 255);
	meta = NULL;
	if (!alloca_to((void **)&meta, sizeof(t_meta)))
		pexit(ERR_ERRNO, errno);
	init(meta);
	build_environ(meta, envp);
	meta->title = argv[0];
	meta->in = argv[1];
	meta->out = argv[4];
	meta->dirs = dirs_by_pathenv(meta, get_environ_by_key(meta, "PATH"));

	char *path;

	path = bin_path(meta, "ls");
	if (!path)
		pexit(ERR_ERRNO, errno);

	/* forked(envp); */
	/* while (proc_cnt--) */
	/* { */
	/* 	pid = fork(); */
	/* 	if (pid == -1) */
	/* 		exit(errno); */
	/* 	if (pid == 0) */
	/* 	{ */
	/* 		forked(envp); */
	/* 		return (0); */
	/* 	} */
	/* } */

	return (0);
}
