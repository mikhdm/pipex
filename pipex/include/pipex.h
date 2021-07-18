/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 21:54:14 by rmander           #+#    #+#             */
/*   Updated: 2021/07/18 18:09:23 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define PATH_SEP "/"

# include "utils.h"

typedef struct s_meta {
	t_list	*env;
}	t_meta;

typedef struct s_kv {
	char	*key;
	char	*value;
}	t_kv;

# endif
