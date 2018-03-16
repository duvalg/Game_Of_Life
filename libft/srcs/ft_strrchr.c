/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:13:25 by gduval            #+#    #+#             */
/*   Updated: 2016/11/12 12:24:44 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
