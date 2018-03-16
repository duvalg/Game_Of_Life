/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:59:40 by gduval            #+#    #+#             */
/*   Updated: 2016/11/14 13:00:12 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!big || !little)
		return (NULL);
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (big[i] == little[j] ||
				(big[i - 1] == little[j - 1] && little[j] == '\0'))
		{
			if (little[j] == '\0')
				return ((char *)big + i - j);
			i++;
			j++;
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
