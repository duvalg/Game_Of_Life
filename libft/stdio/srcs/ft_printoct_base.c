/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:51:51 by gduval            #+#    #+#             */
/*   Updated: 2017/05/16 16:51:52 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_printoct_base(unsigned long long n, int base)
{
	int		i;
	char	*str;
	long	ret;

	i = 0;
	str = ft_strnew(ft_intlen_base(n, base));
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
	return (reverse_string(str));
}
