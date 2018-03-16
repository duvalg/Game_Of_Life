/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:43:00 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 15:24:22 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s)
	{
		i = 0;
		if ((str = ft_memalloc(ft_strlen((char *)s) + 1)))
		{
			while (s[i] != '\0')
			{
				str[i] = (*f)(i, s[i]);
				i++;
			}
		}
		return (str);
	}
	return (NULL);
}
