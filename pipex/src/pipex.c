/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:01:22 by rmander           #+#    #+#             */
/*   Updated: 2021/06/18 21:27:56 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void	child()
{ 
	printf("I'm child with pid (by getpid): %d\n", getpid());
}

int		main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(errno);
	if (pid == 0)
		child();
	else
		printf("I'm parent, who created child with pid: %d\n", pid);
	return (0);
}
