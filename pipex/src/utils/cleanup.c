/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 22:14:33 by rmander           #+#    #+#             */
/*   Updated: 2021/07/29 03:51:19 by mikhaylen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "environ.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static	void	cleandirs(t_meta *data)
{
	char	*dir;
	char	**start;

	if (!data->dirs)
		return ;
	start = data->dirs;
	dir = *data->dirs;
	while (dir)
	{
		free(dir);
		dir = NULL;
		++data->dirs;
		dir = *data->dirs;
	}
	free(start);
	data->dirs = NULL;
}

static	void	cleankv(void *kv)
{
	t_kv	*data;

	data = (t_kv *)kv;
	if (data->key)
		free(data->key);
	if (data->value)
		free(data->value);
	free(kv);
}

static	void	cleanenv(t_meta *data)
{
	if (!data->env)
		return ;
	ft_lstclear(&data->env, cleankv);
	data->env = NULL;
}

static	void	cleancmd(t_meta *data)
{
	int		i;
	char	**strs;
	char	**start;

	i = 0;
	strs = NULL;
	start = NULL;
	while (i < 2)
	{
		if (data->cmd[i])
		{
			start = data->cmd[i];
			strs = data->cmd[i];
			while (*strs)
				free(*strs++);
			free(start);
			start = NULL;
		}
		++i;
	}
}

void	cleanup(void *meta, void *extra)
{
	t_meta	*data;

	data = (t_meta *)meta;
	if (extra)
		free(extra);
	if (data)
	{
		if (data->ifd != -1)
			close(data->ifd);
		if (data->ofd != -1)
			close(data->ofd);
		if (data->pfds[0] != -1)
			close(data->pfds[0]);
		if (data->pfds[1] != -1)
			close(data->pfds[1]);
		cleandirs(data);
		cleanenv(data);
		cleancmd(data);
		free(data);
	}
	data = NULL;
	meta = NULL;
}
