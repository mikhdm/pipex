/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:49:32 by rmander           #+#    #+#             */
/*   Updated: 2021/07/13 23:15:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prev;
	t_list	*curr;

	prev = *lst;
	curr = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = new;
}
