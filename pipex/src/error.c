/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:09:27 by rmander           #+#    #+#             */
/*   Updated: 2021/07/13 23:49:27 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	puterror(int const code)
{
	int			count;
	const char	*errors[] = {"Invalid arguments"};

	count = (int)(sizeof(errors) / sizeof(*errors)); 
	if ((code != ERR_ERRNO) && (code < 0 || code >= count))
		return ;
	if (code == ERR_ERRNO)
	{
		perror(NULL);
		return ;
	}
	ft_putendl_fd((char *)errors[code], STDERR_FILENO);
}

void	pexit(int const code, int status)
{
	puterror(code);
	exit(status);
}

void	pexitfree(int const code, int status, void *data)
{
	if (data)
		cleanup(data);
	pexit(code, status);
}
