/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:41:41 by gduval            #+#    #+#             */
/*   Updated: 2017/04/27 17:41:42 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_putwcharstri(wchar_t *str, int len, t_printf *params)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putwchar(*str, params);
		i++;
	}
}

static void		print_c_uppercase(wchar_t *ret, wchar_t null, va_list vl,
	t_printf *params)
{
	wchar_t	c;
	int		size;

	c = va_arg(vl, int);
	ret[0] = 'a';
	ret[1] = null;
	ret = width_gestion_unicode(ret, params);
	size = ft_strwlen(ret);
	if (params->minus == 1)
		ret[0] = c;
	else
		ret[size - 1] = c;
	ft_putwcharstri(ret, size, params);
}

static void		print_unicode_string(wchar_t *str, va_list vl, t_printf *params)
{
	int			isnull;

	isnull = 0;
	if (params->precision != 0)
		str = va_arg(vl, wchar_t *);
	else
	{
		str = L"";
		va_arg(vl, wchar_t *);
	}
	if (str == NULL)
	{
		isnull = 1;
		str = ft_strwdup(L"\0");
	}
	else
		str = ft_strwdup(str);
	str = add_precision_unicode(str, params);
	str = width_gestion_unicode(str, params);
	if (isnull == 0)
		ft_putwcharstr(str, params);
	else
		ft_putwcharstr(L"(null)", params);
	ft_memdel((void **)&str);
}

void			print_unicode_char(va_list vl, t_printf *params)
{
	char		c;
	wchar_t		null;
	wchar_t		*str;

	str = NULL;
	if (GLOBAL->type == 'c')
	{
		c = va_arg(vl, int);
		ft_putchar(c);
	}
	else if (GLOBAL->type == 'C')
	{
		if (!(str = ft_memalloc(sizeof(sizeof(wchar_t) * 2))))
		{
			ft_exit(params, GLOBAL, vl);
			exit(0);
		}
		null = '\0';
		print_c_uppercase(str, null, vl, params);
		ft_memdel((void **)&str);
	}
	else if (GLOBAL->type == 'S')
		print_unicode_string(str, vl, params);
}
