/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:38:32 by gduval            #+#    #+#             */
/*   Updated: 2017/06/02 11:38:34 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	bigger_char(wchar_t c, t_printf *params)
{
	if (c <= 0x10FFFF && MB_CUR_MAX >= 4)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0xE0) + 0x80);
		ft_putchar(((c >> 6) & 0xE0) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
		GLOBAL->count_letters += 3;
	}
	else
		ft_putchar(c);
}

void		ft_putwchar(wchar_t c, t_printf *params)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
		GLOBAL->count_letters += 1;
	}
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3f) + 0x80);
		ft_putchar((c & 0x3f) + 0x80);
		GLOBAL->count_letters += 2;
	}
	else
		bigger_char(c, params);
	GLOBAL->count_letters += 1;
}
