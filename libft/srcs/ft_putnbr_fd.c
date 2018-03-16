/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbri_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:46:38 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 13:39:33 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putnbr_fd(int n, int fd)
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
		write(fd, "-", 1);
	while (div != 0)
	{
		ft_putchar_fd((nb / div) + '0', fd);
		nb = nb - ((nb / div) * div);
		div = div / 10;
	}
}
