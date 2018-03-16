/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:22:16 by gduval            #+#    #+#             */
/*   Updated: 2016/11/15 13:21:10 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*p_dst;
	char	*p_src;
	void	*ptr;

	i = 0;
	if (!dst || !src || !c || !n)
		return (NULL);
	p_dst = (char *)dst;
	p_src = (char *)src;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		if (p_src[i] == c)
		{
			ptr = &dst + i + 1;
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
