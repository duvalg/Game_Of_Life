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

static char	*ft_result(long n, int div, int negative)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (negative == 0) ? ft_strnew(ft_intlen(n)) : \
				ft_strnew(ft_intlen((n)) + 1)))
		return (NULL);
	res[i] = (negative == 1) ? '-' : res[i];
	i = (res[i] == '-') ? 1 : 0;
	while (div != 0)
	{
		res[i] = '0' + (n / div);
		n = n - ((n / div) * div);
		div /= 10;
		i++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		div;
	int		negative;
	long	nb;

	negative = (n < 0) ? 1 : 0;
	nb = ((long)n < 0) ? (long)n * -1 : (long)n;
	div = 1;
	while (nb / div >= 10)
		div *= 10;
	return (ft_result(nb, div, negative));
}
