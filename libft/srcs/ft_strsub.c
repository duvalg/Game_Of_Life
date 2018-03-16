/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:40:33 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 15:27:52 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s)
	{
		if (start >= ft_strlen(s))
			return (NULL);
		if (!(str = ft_strnew(len)))
			return (NULL);
		if (!(ft_memmove(str, s + (start), len)))
			return (NULL);
		return (str);
	}
	return (NULL);
}
