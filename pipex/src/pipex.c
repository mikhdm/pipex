/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:01:22 by rmander           #+#    #+#             */
/*   Updated: 2021/06/18 22:27:11 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

char const *envval(char **envp, char const *name)
{
	(void) name;
	(void) envp; 
	return ("abc");
}

char const	*executable(char const *path, char **envp)
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

void	child(char **envp)
{ 
	char *argv[] = {"/bin/ls", "-al", NULL};
	execve(argv[0], argv, envp);
}

int		main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(errno);
	if (pid == 0)
	{
		child(envp);
		return (0);
	}
	return (0);
}
