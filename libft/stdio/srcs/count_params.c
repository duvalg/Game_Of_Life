/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 12:04:28 by gduval            #+#    #+#             */
/*   Updated: 2017/04/02 12:04:29 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				count_params(const char *format)
{
	int			i;
	int			active;
	int			count;

	i = -1;
	count = 0;
	active = 0;
	while (format[++i])
	{
		if (ft_strchr("sScCpdDioOuUxX", format[i]))
			active = 0;
		if (format[i] == '%' && active == 0)
		{
			if (format[i + 1] == '%')
				i++;
			else
			{
				count++;
				active = 1;
			}
		}
		else if (format[i] == '%' && active == 1)
			active = 0;
	}
	return (count);
}
