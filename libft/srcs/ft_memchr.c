/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:17:14 by gduval            #+#    #+#             */
/*   Updated: 2016/11/22 15:26:49 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;
	unsigned char	*ptr;

	i = 0;
	s_ptr = (unsigned char *)s;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if (s_ptr[i] == (unsigned char)c)
		{
			ptr = &s_ptr[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
