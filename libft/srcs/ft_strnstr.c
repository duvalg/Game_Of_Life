/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:59:40 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 13:32:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!big || !little)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		if ((i + ft_strlen(little)) > len)
			return (NULL);
		if (big[i] == little[0])
		{
			if (ft_strcmp(ft_strsub(big, i, ft_strlen(little)), little) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (ft_strlen(little) == 0) ? (char *)big : NULL;
}
