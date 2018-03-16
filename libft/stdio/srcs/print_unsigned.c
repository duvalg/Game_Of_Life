/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:11:06 by gduval            #+#    #+#             */
/*   Updated: 2017/04/10 15:11:07 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

static char			*ft_itoa_unsigned(unsigned long long n)
{
	int					i;
	unsigned long long	div;
	unsigned long long	nb;
	char				*res;

	i = 0;
	nb = n;
	div = 1;
	while (nb / div >= 10)
		div *= 10;
	if (!(res = ft_strnew(ft_intlen(nb))))
		return (NULL);
	while (div != 0)
	{
		res[i] = '0' + (nb / div);
		nb = nb - ((nb / div) * div);
		div /= 10;
		i++;
	}
	return (res);
}

static char			*ft_itoa_d_uppercase(unsigned long n)
{
	int				i;
	int				negative;
	long			div;
	unsigned long	nb;
	char			*res;

	negative = ((long)n < 0) ? 1 : 0;
	nb = ((long)n < 0) ? (long)n * -1 : (long)n;
	div = 1;
	while (nb / div >= 10)
		div *= 10;
	i = 0;
	if (!(res = (negative == 0) ? ft_strnew(ft_intlen(nb)) : \
				ft_strnew(ft_intlen((nb)) + 1)))
		return (NULL);
	res[i] = (negative == 1) ? '-' : res[i];
	i = (res[i] == '-') ? 1 : 0;
	while (div != 0)
	{
		res[i] = '0' + (nb / div);
		nb = nb - ((nb / div) * div);
		div /= 10;
		i++;
	}
	return (res);
}

char				*init_tmp(va_list vl, t_printf *params)
{
	char				*tmp;
	unsigned long long	ret_uns_long_long;
	unsigned int		ret_uns;

	if (GLOBAL->type == 'u')
	{
		if (!(tmp = flags_gestion_unsigned(vl, params)))
		{
			ret_uns = va_arg(vl, unsigned int);
			tmp = ft_itoa_unsigned(ret_uns);
		}
	}
	else if (GLOBAL->type == 'U')
	{
		if (!(tmp = flags_gestion_unsigned(vl, params)))
		{
			ret_uns_long_long = va_arg(vl, unsigned long long);
			tmp = ft_itoa_unsigned(ret_uns_long_long);
		}
	}
	else
		tmp = NULL;
	return (tmp);
}

void				print_unsigned(va_list vl, t_printf *params)
{
	char				*tmp;
	unsigned long		ret_uns_long;

	if (!(tmp = init_tmp(vl, params)))
	{
		if (!(tmp = flags_gestion_unsigned(vl, params)))
		{
			ret_uns_long = va_arg(vl, unsigned long);
			tmp = ft_itoa_d_uppercase(ret_uns_long);
		}
	}
	if (ft_atoi(tmp) == 0 && params->precision == 0)
	{
		ft_strdel(&tmp);
		tmp = ft_strdup("");
	}
	tmp = add_precision(tmp, params);
	tmp = width_gestion(tmp, params);
	if (GLOBAL->type == 'D')
		tmp = add_space(tmp, params);
	GLOBAL->count_letters += ft_strlen(tmp);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
}
