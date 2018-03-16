/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:32:30 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 14:42:37 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return ((char *)s + i);
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
