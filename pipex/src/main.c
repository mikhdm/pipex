/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:01:08 by rmander           #+#    #+#             */
/*   Updated: 2021/07/20 01:35:50 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include "error.h"
#include "environ.h"
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

static void	init(t_meta *meta)
{
	meta->title = NULL;
	meta->env = NULL;
	meta->in = NULL;
	meta->out = NULL;
	meta->dirs = NULL;
}

static void process(t_meta *meta, const char *cmd, int fds[2], short int flag)
{
	int		closed;
	char	*path;
	char 	**strs;

	closed = close(fds[1]);
	path = NULL;
	if (closed == -1)
		pexitfree(ERR_ERRNO, errno, meta, NULL);
	strs = ft_splitf(cmd, ft_isspace);
	if (!strs)
		pexitfree(ERR_ERRNO, errno, meta, NULL);
	path = bin_path(meta, strs[0]);
	execve(path, strs, meta->envp);
}

int		main(int argc, char **argv, char **envp)
{
	t_meta		*meta;
	int 		fds[2];
	int 		piped;
	pid_t		forked;

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
	meta->envp = envp;
	meta->dirs = dirs_by_pathenv(meta, get_environ_by_key(meta, "PATH"));

	/* TODO pipelines in progress */

	int			count;
	int			i;
	short int	flag;
	count = argc - 3;
	i = 0;
	flag = -1;
	while (i < count)
	{
		piped = pipe(fds);
		if (piped == -1)
			pexitfree(ERR_ERRNO, errno, meta, NULL);
		close(fds[0]);
		forked = fork();
		if (forked == -1)
			pexitfree(ERR_ERRNO, errno, meta, NULL);
		if (forked == 0)
		{
			if (i == 0)
				flag = IN;
			else if (i == (count - 1))
				flag = OUT;
			process(meta, argv[i + 2], fds, flag);
		}
		else if (forked > 0)
			waitpid(forked, NULL, 0);
		++i;
	}
	return (0);
}
