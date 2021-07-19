/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:01:22 by rmander           #+#    #+#             */
/*   Updated: 2021/07/19 23:16:27 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "error.h"
#include "utils.h"
#include <unistd.h>
#include <errno.h>

char 	**dirs_by_pathenv(t_meta *meta, const char *path)
{
	char **strs;
	if (!path)
		return (NULL);
	strs = ft_split(path, ':');
	if (!strs)
		pexitfree(ERR_ERRNO, errno, meta, NULL);
	return (strs);
}

char	*bin_path(t_meta *meta, const char *base) 
{
	char	*slashed;
	int		ok;
	char	*path;
	char	**dirs;

	slashed = ft_strchr(base, '/');
	dirs = NULL;
	path = NULL;
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
	}
	return (NULL);
}
