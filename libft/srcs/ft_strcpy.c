/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:44:35 by gduval            #+#    #+#             */
/*   Updated: 2016/11/09 18:35:16 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (dst);
}
