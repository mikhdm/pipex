/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:01:22 by rmander           #+#    #+#             */
/*   Updated: 2021/07/18 20:44:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "error.h"
#include "utils.h"
#include "environ.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

char const	*binfile(char const *path, char **envp)
{
	int accessed;
	
	accessed = access(path, F_OK | X_OK);
	if (accessed == -1) 
		exit(errno);
	if (accessed == 0)
		return (path);

	/* TODO */

	(void) envp;
	return (path);
}

void	forked(char **envp)
{ 
	char *argv[] = {"/bin/ls", "-al", NULL};
	execve(argv[0], argv, envp);
}

int		main(int argc, char **argv, char **envp)
{
	t_meta	*meta;

	(void) argv;

	if (argc < 5)
		pexit(ERR_ARGS_WRONG, 255);
	meta = malloc(sizeof(t_meta));
	if (!meta)
		pexit(ERR_ERRNO, errno);
	build_environ(meta, envp);

	t_list	*env;
	t_kv	*kv;

	env = meta->env;
	kv = NULL;
	while (env)
	{
		kv = (t_kv *) env->content;
		printf("%s = %s\n", kv->key, kv->value);
		++env;
	}

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
