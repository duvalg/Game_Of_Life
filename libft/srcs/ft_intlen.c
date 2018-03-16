/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:10:46 by gduval            #+#    #+#             */
/*   Updated: 2016/11/25 16:53:26 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_intlen(unsigned long long n)
{
	unsigned long long	len;
	unsigned long long	tmp;

	len = 1;
	tmp = n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}
