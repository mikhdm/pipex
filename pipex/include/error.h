/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:09:36 by rmander           #+#    #+#             */
/*   Updated: 2021/07/30 17:51:15 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "pipex.h"

# define CODE_ERRNO				(-1)
# define CODE_ARGS_WRONG		0
# define CODE_EMPTY_COMMAND		1
# define CODE_EMPTY_FILE		2
# define CODE_CMD_NOT_FOUND		3

# define EXIT_CMD_FAILURE		-1

void	pexit(int const code, int status, char *title);
void	pexitfree(int const code, int status, t_meta *meta, void *extra);

#endif
