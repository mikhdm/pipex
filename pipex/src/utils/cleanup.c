/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 22:14:33 by rmander           #+#    #+#             */
/*   Updated: 2021/07/28 00:32:48 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "environ.h"
#include <unistd.h>
#include <stdlib.h>

static void	cleandirs(t_meta *data)
{
	char	*dir;

	dir = *data->dirs;
	while (dir)
	{
		free(dir);
		dir = NULL;
		++data->dirs;
		dir = *data->dirs; 
	}
	data->dirs = NULL;
}

static void cleankv(void *kv)
{
	t_kv *data;

	data = (t_kv *)kv;
	if (data->key)
		free(data->key);
	if (data->value)
		free(data->value);
	free(kv);
}

static void	cleanenv(t_meta *data)
{
	ft_lstclear(&data->env, cleankv);
	data->env = NULL;
}

void		cleanup(void *meta, void *extra)
{
	t_meta	*data;

	data = (t_meta *)meta;
	if (extra)
		free(extra);
	if (data)
	{
		if (data->ifd > STDERR_FILENO)
			close(data->ifd);
		if (data->ofd > STDERR_FILENO)
			close(data->ofd);
		if (data->pfds[0] > STDERR_FILENO)
			close(data->pfds[0]);
		if (data->pfds[1] > STDERR_FILENO)
			close(data->pfds[1]);
		if (data->dirs)
			cleandirs(data);
		if (data->env)
			cleanenv(data);
		free(data);
	}
	data = NULL;
	meta = NULL;
}
