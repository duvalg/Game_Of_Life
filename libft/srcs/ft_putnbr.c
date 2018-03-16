/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:46:38 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 11:33:37 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putnbr(int n)
{
	size_t	div;
	size_t	negative;
	long	nb;

	div = 1;
	negative = ((long)n < 0) ? 1 : 0;
	nb = ((long)n < 0) ? (long)n * -1 : (long)n;
	while (nb / div >= 10)
		div *= 10;
	if (negative == 1)
		write(1, "-", 1);
	while (div != 0)
	{
		ft_putchar((nb / div) + '0');
		nb = nb - ((nb / div) * div);
		div = div / 10;
	}
}
