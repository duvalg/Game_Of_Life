/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:47:57 by gduval            #+#    #+#             */
/*   Updated: 2017/04/06 18:48:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bitoi(unsigned long long n)
{
	int	decimal;
	int	i;
	int	rem;

	i = 0;
	decimal = 0;
	while (n != 0)
	{
		rem = n % 10;
		n /= 10;
		decimal = decimal + rem * ft_power(2, i++);
	}
	return (decimal);
}
