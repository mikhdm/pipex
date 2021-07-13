/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:19:50 by rmander           #+#    #+#             */
/*   Updated: 2021/07/13 23:30:58 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stddef.h>

# define IN		0
# define OUT	1

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_splitf(char const *s, int (*f)(int));
char	*ft_strdup_until(const char *s1, const char sym);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen_until(const char *s, const char sym);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst,
							void *(*f)(void *),
							void (*del)(void *));

#endif
