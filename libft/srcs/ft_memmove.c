/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:15:13 by gduval            #+#    #+#             */
/*   Updated: 2016/11/25 17:31:44 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p_dst;
	char	*p_src;

	i = 0;
	p_dst = (char *)dst;
	p_src = (char *)src;
	if (!dst || !src)
		return ("NULL");
	while (i++ < len && src > dst)
		p_dst[i - 1] = p_src[i - 1];
	while (len-- != 0 && src < dst)
		p_dst[len] = p_src[len];
	return (dst);
}
