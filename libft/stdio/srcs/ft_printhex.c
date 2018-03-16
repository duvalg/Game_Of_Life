/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:36:11 by gduval            #+#    #+#             */
/*   Updated: 2017/04/08 13:36:12 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_printhex(uintmax_t n, int base)
{
	int			i;
	char		*str;
	uintmax_t	ret;

	if (!(str = ft_strnew(ft_intlen_base(n, base))))
		return (NULL);
	i = 0;
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (n != 0)
	{
		ret = n % base;
		str[i++] = (ret > 9) ? (ret - 10) + 'a' : ret + '0';
		n = n / base;
	}
	str[i] = '\0';
	return (reverse_string(str));
}
