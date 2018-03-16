/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:13:27 by gduval            #+#    #+#             */
/*   Updated: 2017/06/06 18:13:29 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

wchar_t		*ft_strwsub(wchar_t const *s, unsigned int start, size_t len,
	int option)
{
	size_t	i;
	wchar_t	null;
	wchar_t	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (!(sub = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	null = L'\0';
	sub[len] = null;
	if (option == 1)
		ft_memdel((void **)&s);
	return (sub);
}
