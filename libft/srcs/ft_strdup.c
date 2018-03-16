/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:24:24 by gduval            #+#    #+#             */
/*   Updated: 2016/11/16 14:40:33 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
		++i;
	if ((dup = ft_strnew(i)))
	{
		i = -1;
		while (src[++i])
			dup[i] = src[i];
		dup[i] = src[i];
		return (dup);
	}
	return (NULL);
}
