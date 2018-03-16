/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:09:57 by gduval            #+#    #+#             */
/*   Updated: 2017/05/17 18:10:06 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

wchar_t	*ft_strwjoin(wchar_t *s1, wchar_t *s2, int option)
{
	wchar_t	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	str = ft_memalloc(sizeof(wchar_t) * (ft_strwlen(s1) + ft_strwlen(s2) + 1));
	str[ft_strwlen(s1) + ft_strwlen(s2)] = '\0';
	if (str)
	{
		while (s1[++i])
			str[i] = s1[i];
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		if (option == 1 || option == 3)
			ft_memdel((void **)&s1);
		if (option == 2 || option == 3)
			ft_memdel((void **)&s2);
		return (str);
	}
	return (NULL);
}
