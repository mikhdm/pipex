/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_by_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:52:03 by rmander           #+#    #+#             */
/*   Updated: 2021/07/30 17:37:50 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_func_child	child_by_index(int index,
					t_func_child l, t_func_child r)
{
	if (index == 0)
		return (l);
	return (r);
}
