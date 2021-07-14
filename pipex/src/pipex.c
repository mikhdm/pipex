/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:01:22 by rmander           #+#    #+#             */
/*   Updated: 2021/07/14 20:29:22 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

t_list	buildenv(char **envp)
{
	t_list	env;
	char	*eq;
	char	*kv[2];
	
	eq = NULL;
	kv[0] = NULL;
	kv[1] = NULL;
	while (*envp)
	{	
		eq = ft_strchr(*envp, '=');
		kv[0] = ft_strdup_until(*envp, *eq); 
		if (kv[0])
			/* TODO */
			pexitfree(ERR_ERRNO, errno, /* t_meta */); 
		envp++;
	}
	return (env);
}


/* char const getenvv(t_list **envp, char const *name) */
/* { */

/* 	return ("abc"); */
/* } */

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
	pid_t	pid;
	size_t	proccnt;
	t_list	env;

	(void) argv;
	(void) pid;

	if (argc < 5)
		pexit(ERR_ARGS_WRONG, 255);
	env = buildenv(envp);
	proccnt = argc - 3;
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
