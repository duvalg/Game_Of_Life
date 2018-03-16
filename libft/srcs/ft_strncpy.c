/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:04:08 by gduval            #+#    #+#             */
/*   Updated: 2016/11/18 15:44:16 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (i++ < len)
	{
		if (src[i - 1] == '\0')
		{
			while (i <= len)
			{
				dst[i - 1] = '\0';
				i++;
			}
		}
		else
			dst[i - 1] = src[i - 1];
	}
	return (dst);
}
