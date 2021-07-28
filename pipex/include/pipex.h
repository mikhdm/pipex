/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 21:54:14 by rmander           #+#    #+#             */
/*   Updated: 2021/07/28 19:07:35 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "utils.h"
# include <sys/types.h>

typedef struct s_meta {
	char 	*title;
	char 	*in;
	char 	*out;
	int		ifd;
	int		ofd;
	pid_t	pids[2];
	int		pfds[2];
	char 	**envp;
	char 	**dirs;
	t_list	*env;
	char	**cmd[2];
}	t_meta;

void		init(t_meta *meta);
void		setup(t_meta *meta, char **argv, char **envp);
char		*bin(t_meta *meta, const char *base);
char		**dirs(t_meta *meta, const char *path);

# endif
