/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:09:36 by rmander           #+#    #+#             */
/*   Updated: 2021/07/20 01:17:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "pipex.h"

# define ERR_ERRNO (-1) 

typedef enum e_error
{
	ERR_ARGS_WRONG = 0,
}	t_error;

void	puterror(int const code);
void	pexit(int const code, int status);
void	pexitfree(int const code, int status, t_meta *meta, void *extra);

#endif
