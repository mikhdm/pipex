/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:17:32 by rmander           #+#    #+#             */
/*   Updated: 2021/07/13 22:30:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	endl;

	if (fd < 0)
		return ;
	endl = '\n';
	ft_putstr_fd(s, fd);
	write(fd, &endl, sizeof(char));
}
