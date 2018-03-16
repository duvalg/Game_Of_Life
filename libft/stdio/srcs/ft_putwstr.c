/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:38:58 by gduval            #+#    #+#             */
/*   Updated: 2017/06/02 11:39:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putwcharstr(wchar_t *str, t_printf *params)
{
	while (*str)
	{
		ft_putwchar(*str, params);
		str++;
	}
}
