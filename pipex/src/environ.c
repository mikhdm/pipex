/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:34:58 by rmander           #+#    #+#             */
/*   Updated: 2021/07/28 21:19:29 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "error.h"
#include "utils.h"
#include "environ.h"
#include <stdlib.h>

static void	add_environ(t_meta *meta, t_kv *kv) 
{
	t_list	*node;

	node = ft_lstnew(kv);
	if (!node)
		pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, kv);
	if (meta->env)
		ft_lstadd_back(&(meta->env), node); 
	else
		meta->env = node;
}

/*
*
* build_environ - fill up meta->env as linked list of t_kv (key, value) content. 
*
*/
void	build_environ(t_meta *meta, char **envp)
{
	t_kv	*kv;
	char	*curr;

	kv = NULL;
	curr = NULL;
	while (*envp)
	{
		curr = *envp;
		if (!alloca_to((void **) &kv, sizeof(t_kv)))
			pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, NULL);
		kv->key = ft_strdup_until(curr, '=');
		if (!kv->key)
			pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, kv);
		curr = ft_strchr(curr, '=');
		kv->value = ft_strdup_until(++curr, '\0');
		if (!kv->value)
		{
			free(kv->key);
			pexitfree(ERR_ERRNO, EXIT_FAILURE, meta, kv);
		}
		add_environ(meta, kv);
		kv = NULL;
		envp++;
	}
}

char	*get_environ_by_key(t_meta *meta, const char *key)
{
	t_list	*curr;
	t_kv	*kv;

	curr = meta->env;
	kv = NULL;
	while (curr)
	{
		kv = (t_kv *)curr->content;
		if (ft_strcmp(kv->key, key) == 0)
			return (kv->value);
		curr = curr->next;
	}
	return (NULL);
}
