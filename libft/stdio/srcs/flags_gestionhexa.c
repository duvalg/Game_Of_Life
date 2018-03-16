/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_gestionhexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:48:27 by gduval            #+#    #+#             */
/*   Updated: 2017/05/17 15:48:28 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "limits.h"

static char	*hexa_gestion(intmax_t nb, t_printf *params)
{
	char		*ret;
	intmax_t	result;

	result = 0;
	ret = ft_printhex(nb, 16);
	return (GLOBAL->type == 'x') ? ret : upper(ret);
}

char		*flags_gestionhexa(va_list vl, t_printf *params)
{
	char				*ret;

	if (params->ll == 1)
		ret = hexa_gestion((unsigned long long)va_arg(vl, uintmax_t), params);
	else if (params->l == 1)
		ret = hexa_gestion((unsigned long)va_arg(vl, uintmax_t), params);
	else if (params->hh == 1)
		ret = hexa_gestion((unsigned char)va_arg(vl, uintmax_t), params);
	else if (params->h == 1)
		ret = hexa_gestion((unsigned short)va_arg(vl, uintmax_t), params);
	else if (params->z == 1)
		ret = hexa_gestion((size_t)va_arg(vl, uintmax_t), params);
	else if (params->j == 1)
		ret = hexa_gestion((uintmax_t)va_arg(vl, uintmax_t), params);
	else
		ret = hexa_gestion(va_arg(vl, unsigned int), params);
	return (ret);
}
