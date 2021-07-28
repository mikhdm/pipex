/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:01:22 by rmander           #+#    #+#             */
/*   Updated: 2021/07/28 19:06:28 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "error.h"
#include "environ.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

char 	**dirs(t_meta *meta, const char *path)
{
	char **strs;
	if (!path)
		return (NULL);
	strs = ft_split(path, ':');
	if (!strs)
		pexitfree(ERR_ERRNO, errno, meta, NULL);
	return (strs);
}

char	*bin(t_meta *meta, const char *base) 
{
	char	*slashed;
	int		ok;
	char	*path;
	char	**dirs;

	dirs = NULL;
	path = NULL;
	slashed = ft_strchr(base, '/');
	if (!base)
		return (NULL);
	if (slashed)
	{
		ok = access(base, F_OK | X_OK);
		if (ok == 0)
			return ((char *)base);
		return (NULL);
	}
	dirs = meta->dirs;
	while (*dirs)
	{
		path = ft_strjoin(*dirs, "/");
		if (!path)
			pexitfree(ERR_ERRNO, errno, meta, NULL);
		path = ft_strjoin(path, base);
		if (!path)
			pexitfree(ERR_ERRNO, errno, meta, path);
		ok = access(path, F_OK | X_OK);
		if (ok == 0)
			return (path);
		++dirs;
	}
	return (NULL);
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
		if (!raw)
			pexitfree(ERR_EMPTY_COMMAND, 255, meta, NULL);
		strs = ft_splitf(raw, ft_isspace); 
		if (!strs)
			pexitfree(ERR_ERRNO, errno, meta, NULL);
		meta->cmd[i] = strs;
	}
}

void	setup(t_meta *meta, char **argv, char **envp)
{
	build_environ(meta, envp);
	set_cmdlist(meta, argv);
	meta->title = argv[0];
	if (!argv[1])
		pexitfree(ERR_EMPTY_FILE, 255, meta, NULL);
	if (!argv[4])
		pexitfree(ERR_EMPTY_FILE, 255, meta, NULL);
	meta->in = argv[1];
	meta->out = argv[4];
	meta->envp = envp;
	meta->dirs = dirs(meta, get_environ_by_key(meta, "PATH"));
}
