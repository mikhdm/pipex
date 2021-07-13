/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:44:50 by rmander           #+#    #+#             */
/*   Updated: 2021/07/13 23:17:05 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*prev;

	prev = NULL;
	while (lst)
	{
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}
