/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:34:46 by rmander           #+#    #+#             */
/*   Updated: 2021/07/19 23:06:24 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

#include "utils.h"
#include "pipex.h"

typedef struct s_kv {
	char	*key;
	char	*value;
}	t_kv;

void	build_environ(t_meta *meta, char **envp);
char	*get_environ_by_key(t_meta *meta, const char *key);

#endif
