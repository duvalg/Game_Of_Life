/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legb83 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:10:46 by legb83            #+#    #+#             */
/*   Updated: 2016/11/25 16:53:26 by legb83           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_intlen_base(unsigned long long n, int base)
{
	unsigned long long	len;
	unsigned long long	tmp;

	len = 1;
	tmp = n;
	while (tmp >= (unsigned long long)base)
	{
		tmp /= base;
		len++;
	}
	return (len);
}
