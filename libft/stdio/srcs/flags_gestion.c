/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:46:15 by gduval            #+#    #+#             */
/*   Updated: 2017/05/15 17:46:16 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_itoamax_uns(unsigned long long n)
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

static char		*ft_itoamax(unsigned long long n)
{
	int				i;
	int				negative;
	long			div;
	unsigned long	nb;
	char			*res;

	negative = ((long long)n < 0) ? 1 : 0;
	nb = ((long long)n < 0) ? (long long)n * -1 : (long long)n;
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

char			*flags_gestion(va_list vl, t_printf *params)
{
	char	*ret;

	if (params->ll == 1)
		ret = ft_itoamax((long long int)va_arg(vl, uintmax_t));
	else if (params->l == 1)
		ret = ft_itoamax((long int)va_arg(vl, uintmax_t));
	else if (params->hh == 1)
		ret = ft_itoa((char)va_arg(vl, uintmax_t));
	else if (params->h == 1)
		ret = ft_itoa((short int)va_arg(vl, uintmax_t));
	else if (params->z == 1)
		ret = ft_itoamax((size_t)va_arg(vl, uintmax_t));
	else if (params->j == 1)
		ret = ft_itoamax((intmax_t)va_arg(vl, uintmax_t));
	else
		return (NULL);
	return (ret);
}

char			*flags_gestion_base(va_list vl, t_printf *params, int base)
{
	char	*ret;

	if (params->ll == 1)
		ret = ft_itoa_basemax(va_arg(vl, uintmax_t), base);
	else if (params->l == 1)
		ret = ft_itoa_basemax((unsigned long long)va_arg(vl, uintmax_t), base);
	else if (params->hh == 1)
		ret = ft_itoa_basemax((unsigned char)va_arg(vl, uintmax_t), base);
	else if (params->h == 1)
		ret = ft_itoa_basemax((unsigned short)va_arg(vl, uintmax_t), base);
	else if (params->z == 1)
		ret = ft_itoa_basemax((unsigned long)va_arg(vl, uintmax_t), base);
	else if (params->j == 1)
		ret = ft_itoa_basemax((uintmax_t)va_arg(vl, uintmax_t), base);
	else
		return (NULL);
	return (ret);
}

char			*flags_gestion_unsigned(va_list vl, t_printf *params)
{
	char	*ret;

	if (params->ll == 1)
		ret = ft_itoamax_uns((long long int)va_arg(vl, uintmax_t));
	else if (params->l == 1)
		ret = ft_itoamax_uns((long int)va_arg(vl, uintmax_t));
	else if (params->hh == 1)
		ret = (GLOBAL->type == 'U' || GLOBAL->type == 'D') ? \
		ft_itoamax_uns((double)va_arg(vl, uintmax_t)) : \
		ft_itoamax_uns((unsigned char)va_arg(vl, uintmax_t));
	else if (params->h == 1)
		ret = ft_itoamax_uns((unsigned long)va_arg(vl, uintmax_t));
	else if (params->z == 1)
		ret = ft_itoamax_uns((size_t)va_arg(vl, uintmax_t));
	else if (params->j == 1)
		ret = ft_itoamax_uns((intmax_t)va_arg(vl, uintmax_t));
	else
		return (NULL);
	return (ret);
}
