/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 23:08:55 by rmander           #+#    #+#             */
/*   Updated: 2021/07/30 18:20:16 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "error.h"
#include <unistd.h>
#include <stdlib.h>

char	*lookup(t_meta *meta, const char *base)
{
	char	*tmp;
	char	*path;
	char	**dirs;

	tmp = NULL;
	path = NULL;
	dirs = meta->dirs;
	if (!dirs)
		return (NULL);
	while (*dirs)
	{
		tmp = ft_strjoin(*dirs++, "/");
		if (!tmp)
			pexitfree(CODE_ERRNO, EXIT_FAILURE, meta, NULL);
		path = ft_strjoin(tmp, base);
		if (!path)
			pexitfree(CODE_ERRNO, EXIT_FAILURE, meta, tmp);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		path = NULL;
		tmp = NULL;
	}
	return (NULL);
}

char	*getbin(void *meta, const char *base)
{
	t_meta	*data;

	data = (t_meta *)meta;
	if (!base)
		return (NULL);
	if (ft_strchr(base, '/'))
	{
		if (access(base, F_OK | X_OK) == 0)
			return ((char *)base);
		return (NULL);
	}
	return (lookup(data, base));
}
