/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:33:53 by gduval            #+#    #+#             */
/*   Updated: 2017/08/04 15:08:25 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	if_empty(char *str, intmax_t n)
{
	int i;

	i = 0;
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (1);
	}
	return (0);
}

char		*ft_itoa_basemax(intmax_t n, int base)
{
	int		i;
	char	*str;
	int		ret;

	i = 0;
	str = ft_strnew(ft_intlen_base(n, base));
	if (if_empty(str, n))
		return (str);
	while (n != 0)
	{
		ret = n % base;
		str[i++] = (ret > 9) ? (ret - 10) + 'a' : ret + '0';
		n = n / base;
	}
	str[i] = '\0';
	return (reverse_string(str));
}
