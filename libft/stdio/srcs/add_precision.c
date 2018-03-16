/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:45:47 by gduval            #+#    #+#             */
/*   Updated: 2017/05/04 16:45:48 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*add_precision(char *str, t_printf *params)
{
	char	*tmp;
	char	*list_str;
	int		size;

	if (!str || !params)
		return (NULL);
	list_str = "sScC";
	if (ft_strchr(list_str, GLOBAL->type))
	{
		if (params->precision < (int)ft_strlen(str) \
		&& (GLOBAL->activate_precision == 1))
		{
			if (params->precision < 0)
				size = 0;
			else
				size = params->precision;
			tmp = ft_strsub(str, 0, size);
			ft_memdel((void **)&str);
			return (tmp);
		}
	}
	else
		return (nb_precision(str, params));
	return (str);
}

wchar_t			*add_precision_unicode(wchar_t *str, t_printf *params)
{
	wchar_t	*tmp;
	int		size;

	if (!str || !params)
		return (NULL);
	if (params->precision < (int)ft_strwlenplus(str) \
	&& (GLOBAL->activate_precision == 1))
	{
		if (params->precision < 0)
			size = 0;
		else
			size = params->precision;
		if (!(tmp = ft_strwsub(str, 0, size, 0)))
			return (NULL);
		ft_memdel((void **)&str);
		while (ft_strwlenplus(tmp) > params->precision)
			tmp = ft_strwsub(tmp, 0, ft_strwlen(tmp) - 1, 1);
		return (tmp);
	}
	return (str);
}
