/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:09:27 by rmander           #+#    #+#             */
/*   Updated: 2021/07/29 00:21:56 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	puterror(char *title, int const code)
{
	const char	*errors[] = {"invalid arguments",
		"empty command", "empty file", "command not found"};

	if ((code != ERR_ERRNO)
		&& (code < 0 || code >= (int)(sizeof(errors) / sizeof(*errors))))
		return ;
	if (code == ERR_ERRNO)
	{
		perror(title);
		return ;
	}
	ft_putstr_fd(title, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd((char *)errors[code], STDERR_FILENO);
}

void	pexit(int const code, int status, char *title)
{
	puterror(title, code);
	exit(status);
}

void	pexitfree(int const code, int status, t_meta *meta, void *extra)
{
	char *title;

	title = meta->title;
	cleanup(meta, extra);
	pexit(code, status, title);
}
