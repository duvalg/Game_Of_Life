/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_gestion_unicode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:56:00 by gduval            #+#    #+#             */
/*   Updated: 2017/06/01 14:56:01 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			*ft_memset_unicode(void *s, int c, size_t n)
{
	size_t	i;
	wchar_t	*p_char;

	p_char = (wchar_t *)s;
	i = -1;
	while (++i < n)
		p_char[i] = c;
	return (s);
}

wchar_t			*width_gestion_unicode(wchar_t *str, t_printf *params)
{
	wchar_t	c;
	wchar_t	*width;
	wchar_t	null;
	int		size;

	width = NULL;
	if (params->precision < 0 && GLOBAL->activate_precision == 1)
		params->width = params->precision * -1;
	size = (params->width - ft_strwlenplus(str));
	if (size <= 0)
		return (str);
	c = (params->zero == 1 && params->minus == 0) ? '0' : ' ';
	if (!(width = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	null = '\0';
	width[size - 1] = null;
	ft_memset_unicode(width, c, size);
	if (params->minus == 1)
		return (ft_strwjoin(str, width, 3));
	return (ft_strwjoin(width, str, 3));
}
