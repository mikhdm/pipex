/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:09:36 by rmander           #+#    #+#             */
/*   Updated: 2021/07/28 21:15:30 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "pipex.h"

# define ERR_ERRNO (-1)

typedef enum e_error
{
	ERR_ARGS_WRONG = 0,
	ERR_EMPTY_COMMAND,
	ERR_EMPTY_FILE
}	t_error;

void	pexit(int const code, int status, char *title);
void	pexitfree(int const code, int status, t_meta *meta, void *extra);

#endif
