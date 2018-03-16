/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:39:25 by gduval            #+#    #+#             */
/*   Updated: 2017/04/06 18:43:02 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

float	ft_power(float n, float power)
{
	int		i;
	float	ret;

	i = 1;
	ret = n;
	while (i < power)
	{
		ret = ret * n;
		i++;
	}
	return (ret);
}
