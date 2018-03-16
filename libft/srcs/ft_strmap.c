/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:32:29 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 15:22:50 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (s)
	{
		i = 0;
		if ((str = ft_memalloc(ft_strlen(s) + 1)))
		{
			while (s[i] != '\0')
			{
				str[i] = (*f)(s[i]);
				i++;
			}
		}
		return (str);
	}
	return (NULL);
}
