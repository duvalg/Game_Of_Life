/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 14:49:25 by gduval            #+#    #+#             */
/*   Updated: 2017/06/07 11:58:01 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

static char		*ft_dupstr(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
		i++;
	if (!(dup = (char *)ft_strnew(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = src[i];
	return (dup);
}

static void		print_it(char *ret, int null, t_printf *params)
{
	if (null == 0 || ft_strlen(ret) > 0)
	{
		GLOBAL->count_letters += (int)ft_strlen(ret);
		ft_putstr(ret);
	}
	else
	{
		write(1, "(null)", 6);
		GLOBAL->count_letters += 6;
	}
}

static char		*init_ret(va_list vl, t_printf *params)
{
	if (params->precision != 0)
		return (va_arg(vl, char *));
	else
	{
		va_arg(vl, char *);
		return ("");
	}
}

void			print_string(va_list vl, t_printf *params)
{
	char	*ret;
	int		null;

	null = 0;
	ret = init_ret(vl, params);
	if (ret == NULL)
	{
		null = 1;
		if (!(ret = ft_strnew(1)))
		{
			ft_exit(params, GLOBAL, vl);
			exit(0);
		}
	}
	else
		ret = ft_dupstr(ret);
	ret = add_precision(ret, params);
	ret = width_gestion(ret, params);
	print_it(ret, null, params);
	ft_memdel((void **)&ret);
}
