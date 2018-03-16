/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlenplus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:35:31 by gduval            #+#    #+#             */
/*   Updated: 2017/05/29 15:35:51 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strwlenplus(wchar_t *str)
{
	int		i;
	int		oct;

	i = 0;
	oct = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			oct += 1;
		else if (str[i] <= 0x7FF)
			oct += 2;
		else if (str[i] <= 0xFFFF)
			oct += 3;
		else if (str[i] <= 0x10FFFF)
			oct += 4;
		i++;
	}
	return (oct);
}
