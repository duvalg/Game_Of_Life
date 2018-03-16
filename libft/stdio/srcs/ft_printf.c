/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:44:48 by gduval            #+#    #+#             */
/*   Updated: 2017/03/04 16:04:21 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_printf	*params;
	t_global	*global;
	va_list		vl;
	int			count;

	if (!format)
		return (-1);
	if (!(params = ft_memalloc(sizeof(t_printf))))
		return (-1);
	va_start(vl, format);
	if ((count = start_read(format, params, global, vl)) == -1)
		return (-1);
	count = GLOBAL->count_letters - count;
	ft_exit(params, GLOBAL, vl);
	return (count);
}
