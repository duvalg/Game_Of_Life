/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legb83 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:24:24 by legb83            #+#    #+#             */
/*   Updated: 2016/12/02 12:12:02 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

wchar_t		*ft_strwdup(const wchar_t *src)
{
	int		i;
	wchar_t	null;
	wchar_t	*dup;

	i = 0;
	null = '\0';
	while (src[i] != null)
		i++;
	if ((dup = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (i + 1))))
	{
		i = 0;
		while (src[i] != '\0')
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = src[i];
		return (dup);
	}
	return (NULL);
}
