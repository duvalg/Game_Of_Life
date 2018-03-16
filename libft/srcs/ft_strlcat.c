/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:14:11 by gduval            #+#    #+#             */
/*   Updated: 2016/11/28 17:21:10 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	length;

	i = 0;
	j = 0;
	if (!dst || !src)
		return (0);
	src = ft_strdup(src);
	length = ft_strlen(dst) + ft_strlen(src);
	size = ((int)size < 0) ? length : size;
	if (size == 0)
		return (ft_strlen(src));
	if (ft_strlen(dst) > size)
		return (ft_strlen(src) + size);
	while (dst[i] != '\0' && i < size)
		i++;
	while (i < (size - 1) && src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (length);
}
