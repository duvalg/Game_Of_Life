/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:33:53 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 11:32:13 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	if_empty(char *str, int n)
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

char		*ft_itoa_base(int n, int base)
{
	int		i;
	int		negative;
	char	*str;
	int		ret;

	i = 0;
	negative = 0;
	str = ft_strnew(ft_intlen_base(n, base));
	if (if_empty(str, n))
		return (str);
	if (n < 0 && base == 10)
	{
		negative = 1;
		n = -n;
	}
	while (n != 0)
	{
		ret = n % base;
		str[i++] = (ret > 9) ? (ret - 10) + 'a' : ret + '0';
		n = n / base;
	}
	if (negative)
		str[i++] = '-';
	str[i] = '\0';
	return (reverse_string(str));
}
