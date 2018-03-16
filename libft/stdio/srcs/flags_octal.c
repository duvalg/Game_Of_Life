/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:30:26 by gduval            #+#    #+#             */
/*   Updated: 2017/05/23 13:30:29 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*flagso(va_list vl, t_printf *params)
{
	char				*ret;

	if (params->ll == 1)
		ret = ft_printoct_base(va_arg(vl, uintmax_t), 8);
	else if (params->l == 1)
		ret = ft_printoct_base((unsigned long)va_arg(vl, uintmax_t), 8);
	else if (params->hh == 1)
		ret = ft_printoct_base((unsigned char)va_arg(vl, uintmax_t), 8);
	else if (params->h == 1)
		ret = ft_printoct_base((unsigned short)va_arg(vl, uintmax_t), 8);
	else if (params->z == 1)
		ret = ft_printoct_base((size_t)va_arg(vl, uintmax_t), 8);
	else if (params->j == 1)
		ret = ft_printoct_base((intmax_t)va_arg(vl, uintmax_t), 8);
	else
		return (NULL);
	return (ret);
}

char		*flagso_uppercase(va_list vl, t_printf *params)
{
	char				*ret;

	if (params->ll == 1)
		ret = ft_printoct_base(va_arg(vl, uintmax_t), 8);
	else if (params->l == 1)
		ret = ft_printoct_base((unsigned long)va_arg(vl, uintmax_t), 8);
	else if (params->hh == 1)
		ret = ft_printoct_base((unsigned int)va_arg(vl, uintmax_t), 8);
	else if (params->h == 1)
		ret = ft_printoct_base((unsigned short)va_arg(vl, uintmax_t), 8);
	else if (params->z == 1)
		ret = ft_printoct_base((size_t)va_arg(vl, uintmax_t), 8);
	else if (params->j == 1)
		ret = ft_printoct_base((intmax_t)va_arg(vl, uintmax_t), 8);
	else
		return (NULL);
	return (ret);
}

char		*flags_octal(va_list vl, t_printf *params)
{
	return (GLOBAL->type == 'o') ? flagso(vl, params) : \
	flagso_uppercase(vl, params);
}
