/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:10:15 by gduval            #+#    #+#             */
/*   Updated: 2017/04/07 12:10:16 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_hexa(va_list vl, t_printf *params)
{
	char				*ret;

	ret = flags_gestionhexa(vl, params);
	if (ft_atoi(ret) == 0 && params->precision == 0)
	{
		ft_strdel(&ret);
		ret = ft_strdup("");
	}
	ret = add_precision(ret, params);
	ret = add_hash(ret, params);
	ret = width_gestion(ret, params);
	GLOBAL->count_letters += ft_strlen(ret);
	ft_putstr(ret);
	ft_memdel((void **)&ret);
}
