/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:30:59 by gduval            #+#    #+#             */
/*   Updated: 2017/04/10 13:31:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_it(char **ret, t_printf *params)
{
	if (GLOBAL->type == 'O' || GLOBAL->type == 'o')
	{
		if (ft_atoi(*ret) == 0 && params->precision == 0)
		{
			ft_strdel(ret);
			*ret = ft_strdup("");
		}
		*ret = add_hash(*ret, params);
		*ret = add_precision(*ret, params);
		*ret = width_gestion(*ret, params);
		GLOBAL->count_letters += ft_strlen(*ret);
		ft_putstr(*ret);
		ft_strdel(ret);
	}
}

void			print_octal(va_list vl, t_printf *params)
{
	char				*ret;
	unsigned long long	nb;

	if (GLOBAL->type == 'o')
	{
		if (!(ret = flags_octal(vl, params)))
		{
			nb = va_arg(vl, unsigned int);
			ret = ft_printoct_base(nb, 8);
		}
	}
	else if (GLOBAL->type == 'O')
	{
		if (!(ret = flags_octal(vl, params)))
		{
			nb = va_arg(vl, unsigned long long);
			ret = ft_printoct_base(nb, 8);
		}
	}
	print_it(&ret, params);
}
