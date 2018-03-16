/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:41:32 by gduval            #+#    #+#             */
/*   Updated: 2017/04/03 16:41:33 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print_adress(va_list vl, t_printf *params)
{
	char	*ret;

	ret = ft_printhex((unsigned long long)va_arg(vl, void *), 16);
	if (ft_atoi(ret) == 0 && params->precision == 0)
	{
		ft_strdel(&ret);
		ret = ft_strdup("");
	}
	ret = add_precision(ret, params);
	if (params->zero == 0)
		ret = ft_strjoin_free("0x", ret, 2);
	else
		params->width -= 2;
	ret = width_gestion(ret, params);
	if (params->zero != 0)
		ret = ft_strjoin_free("0x", ret, 2);
	GLOBAL->count_letters += ft_strlen(ret);
	ft_putstr(ret);
	ft_strdel(&ret);
}

static void		print_char(va_list vl, t_printf *params)
{
	char	*ret;
	char	c;
	int		size;

	if (GLOBAL->type == 'C' || GLOBAL->type == 'S')
		print_unicode_char(vl, params);
	else
	{
		if (!(ret = ft_memalloc(sizeof(char) * (1 + 1))))
		{
			ft_exit(params, GLOBAL, vl);
			exit(0);
		}
		c = va_arg(vl, int);
		ret[0] = 'a';
		ret = width_gestion(ret, params);
		size = ft_strlen(ret);
		if (params->minus == 1)
			ret[0] = c;
		else
			ret[size - 1] = c;
		GLOBAL->count_letters += size;
		ft_putstri(ret, size);
		ft_strdel(&ret);
	}
}

static void		print_int(va_list vl, t_printf *params)
{
	char	*ret;

	if (!(ret = flags_gestion(vl, params)))
		ret = ft_itoa(va_arg(vl, int));
	if (ft_atoi(ret) == 0 && params->precision == 0)
	{
		ft_strdel(&ret);
		ret = ft_strdup("");
	}
	ret = add_plus(ret, params);
	ret = add_precision(ret, params);
	ret = add_space(ret, params);
	ret = width_gestion(ret, params);
	GLOBAL->count_letters += ft_strlen(ret);
	ft_putstr(ret);
	ft_strdel(&ret);
}

static void		print_other(va_list vl, t_printf *params)
{
	char	*ret;

	if (!(ret = ft_memalloc(sizeof(char) * (2 + 1))))
	{
		ft_exit(params, GLOBAL, vl);
		exit(0);
	}
	ret[0] = GLOBAL->type;
	ret[1] = '\0';
	ret = add_plus(ret, params);
	ret = width_gestion(ret, params);
	GLOBAL->count_letters += ft_strlen(ret);
	ft_putstr(ret);
	ft_strdel(&ret);
}

void			print_param(va_list vl, t_printf *params)
{
	normalize_flags(params);
	if (GLOBAL->type == 's')
		print_string(vl, params);
	else if (GLOBAL->type == 'd' || GLOBAL->type == 'i')
		print_int(vl, params);
	else if (GLOBAL->type == 'c' || GLOBAL->type == 'C' || GLOBAL->type == 'S')
		print_char(vl, params);
	else if (GLOBAL->type == 'x' || GLOBAL->type == 'X')
		print_hexa(vl, params);
	else if (GLOBAL->type == 'p')
		print_adress(vl, params);
	else if (GLOBAL->type == 'o' || GLOBAL->type == 'O')
		print_octal(vl, params);
	else if (GLOBAL->type == 'u' || GLOBAL->type == 'D' || GLOBAL->type == 'U')
		print_unsigned(vl, params);
	else
		print_other(vl, params);
}
