/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:01:22 by rmander           #+#    #+#             */
/*   Updated: 2021/07/30 17:53:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "error.h"
#include "environ.h"
#include "utils.h"
#include <stdlib.h>
#include <fcntl.h>

char	**dirs(t_meta *meta, const char *path)
{
	char	**strs;

	if (!path)
		return (NULL);
	strs = ft_split(path, ':');
	if (!strs)
		pexitfree(CODE_ERRNO, EXIT_FAILURE, meta, NULL);
	return (strs);
}

/*
* title, in, out, envp - memory located on the stack
* env, dirs, cmd[0], cmd[1] - memory located on a heap
*/
void	init(t_meta *meta)
{
	meta->title = NULL;
	meta->in = NULL;
	meta->out = NULL;
	meta->envp = NULL;
	meta->env = NULL;
	meta->dirs = NULL;
	meta->ifd = -1;
	meta->ofd = -1;
	meta->pfds[0] = -1;
	meta->pfds[1] = -1;
	meta->cmd[0] = NULL;
	meta->cmd[1] = NULL;
	ft_memset(meta->pfds, -1, sizeof(int) * 2);
	ft_memset(meta->pids, -1, sizeof(pid_t) * 2);
}

void	set_cmdlist(t_meta *meta, char **argv)
{
	int		i;
	char	*raw;
	char	**strs;

	i = 0;
	raw = NULL;
	strs = NULL;
	while (i < 2)
	{
		raw = argv[i + 2];
		if (!*raw)
			pexitfree(CODE_EMPTY_COMMAND, EXIT_FAILURE, meta, NULL);
		strs = ft_splitf(raw, ft_isspace);
		if (!strs)
			pexitfree(CODE_ERRNO, EXIT_FAILURE, meta, NULL);
		meta->cmd[i++] = strs;
	}
}

void	setup(t_meta *meta, char **argv, char **envp)
{
	meta->title = argv[0];
	build_environ(meta, envp);
	set_cmdlist(meta, argv);
	if (!*argv[1])
		pexitfree(CODE_EMPTY_FILE, EXIT_FAILURE, meta, NULL);
	meta->in = argv[1];
	if (!*argv[4])
		pexitfree(CODE_EMPTY_FILE, EXIT_FAILURE, meta, NULL);
	meta->out = argv[4];
	meta->envp = envp;
	meta->dirs = dirs(meta, get_environ_by_key(meta, "PATH"));
}
