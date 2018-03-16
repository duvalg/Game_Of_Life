/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:45:22 by gduval            #+#    #+#             */
/*   Updated: 2017/04/22 15:45:23 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		is_there_blank(const char *format, t_printf *params)
{
	int	i;

	i = 0;
	while (format[i++])
	{
		if (format[i] == ' ')
		{
			params->blank++;
			return (params->blank);
		}
	}
	return (0);
}

static int		while_reading(const char *format, t_printf *params, va_list vl,\
	size_t j)
{
	char	*string;

	string = NULL;
	string = ft_strsub(format, GLOBAL->i, (j - 1 - GLOBAL->i + 1));
	is_there_blank(string, params);
	if (get_precision(string, params) == -1)
		return (0);
	string = delete_precision(string, params);
	if (get_width(string, params, vl) == -1)
		return (0);
	print_param(vl, params);
	GLOBAL->i += (j - GLOBAL->i);
	return (1);
}

static int		read_format(const char *format, size_t j, t_printf *params, \
	va_list vl)
{
	while (format[j++])
	{
		if ((GLOBAL->type = is_a_type(format[j])))
			return (!while_reading(format, params, vl, j)) ? -1 : 1;
	}
	if (GLOBAL->type != 0)
		return (0);
	return (0);
}

static int		check_string(const char *format, t_printf *params, va_list vl)
{
	size_t	j;

	j = GLOBAL->i;
	if (format[j + 1] == '%')
	{
		ft_putchar('%');
		GLOBAL->i++;
		return (2);
	}
	if (read_format(format, j, params, vl) == -1)
		return (-1);
	return (0);
}

int				start_read(const char *format, t_printf *params, \
	t_global *global, va_list vl)
{
	int		max_count;

	max_count = count_params(format);
	global = init_global(global);
	while (format[global->i] && global->count <= max_count)
	{
		init_struct(params, global);
		if (format[global->i] == '%')
		{
			if (check_string(format, params, vl) == -1)
				return (-1);
		}
		else
			ft_putchar(format[global->i]);
		GLOBAL->i++;
		GLOBAL->count_letters++;
	}
	init_struct(params, global);
	return (max_count);
}
