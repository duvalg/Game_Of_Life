/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:41:31 by gduval            #+#    #+#             */
/*   Updated: 2016/11/22 14:54:25 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	size_t			i;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n != 0)
	{
		while (i < n)
		{
			if (p_s1[i] != p_s2[i])
				return (p_s1[i] - p_s2[i]);
			i++;
		}
	}
	return (0);
}
