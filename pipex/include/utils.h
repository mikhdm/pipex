/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:19:50 by rmander           #+#    #+#             */
/*   Updated: 2021/06/18 22:25:22 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stddef.h>

# define IN		0
# define OUT	1

char	**ft_split(char const *s, char c);
char	*ft_strdup_until(const char *s1, const char sym);
size_t	ft_strlen_until(const char *s, const char sym);

#endif

