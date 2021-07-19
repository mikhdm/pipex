/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 21:54:14 by rmander           #+#    #+#             */
/*   Updated: 2021/07/20 01:21:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "utils.h"

typedef struct s_meta {
	char 	*title;
	char 	*in;
	char 	*out;
	char 	**envp;
	char 	**dirs;
	t_list	*env;
}	t_meta;

char		**dirs_by_pathenv(t_meta *meta, const char *path);
char		*bin_path(t_meta *meta, const char *base);

# endif
