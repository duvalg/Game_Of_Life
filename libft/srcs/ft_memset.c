/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:52:11 by gduval            #+#    #+#             */
/*   Updated: 2016/11/15 17:10:23 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p_char;

	p_char = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		p_char[i] = c;
		++i;
	}
	return (s);
}
