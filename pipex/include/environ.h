/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:34:46 by rmander           #+#    #+#             */
/*   Updated: 2021/07/18 20:06:34 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

#include "utils.h"
#include "pipex.h"

void	build_environ(t_meta *meta, char **envp);
char	*get_environ_by_key(const char *key);

#endif
