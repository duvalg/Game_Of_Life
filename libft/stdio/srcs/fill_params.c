/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:26:56 by gduval            #+#    #+#             */
/*   Updated: 2017/03/14 11:26:58 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	and_others(const char *s, t_printf *params)
{
	char	*res;

	if (ft_strchr(s, '#'))
	{
		params->hash = 1;
		res = ft_deletestr((char *)s, "#");
		return (fill_params((const char**)&res, params));
	}
	if (ft_strchr(s, '-'))
	{
		if (params->minus == 0)
		{
			params->minus = 1;
			params->zero = 0;
			res = ft_deletestr((char *)s, "-");
			return (fill_params((const char**)&res, params));
		}
	}
	return (0);
}

static int	other_flags(const char *s, t_printf *params)
{
	char	*res;

	if (ft_strchr(s, '0'))
	{
		if (params->zero == 0)
		{
			params->zero = 1;
			res = ft_deletestr((char *)s, "0");
			return (fill_params((const char**)&res, params));
		}
	}
	if (ft_strchr(s, '+'))
	{
		params->blank = 0;
		params->plus = 1;
		res = ft_deletestr((char *)s, "+");
		return (fill_params((const char**)&res, params));
	}
	and_others(s, params);
	return (0);
}

static int	flags_l_ll(const char *s, t_printf *params)
{
	char	*res;

	if (ft_strstr(s, "ll"))
	{
		params->ll = 1;
		res = ft_deletestr((char *)s, "ll");
		return (fill_params((const char**)&res, params));
	}
	if (ft_strchr(s, 'l'))
	{
		params->l = 1;
		res = ft_deletestr((char *)s, "l");
		return (fill_params((const char**)&res, params));
	}
	other_flags(s, params);
	return (0);
}

static int	flags_j_z(const char *s, t_printf *params)
{
	char	*res;

	if (ft_strchr(s, 'j'))
	{
		if (params->j == 0)
		{
			params->j = 1;
			res = ft_deletestr((char *)s, "j");
			return (fill_params((const char**)&res, params));
		}
		return (-1);
	}
	if (ft_strchr(s, 'z'))
	{
		if (params->z == 0)
		{
			params->z = 1;
			res = ft_deletestr((char *)s, "z");
			return (fill_params((const char**)&res, params));
		}
		return (-1);
	}
	if (flags_l_ll(s, params) == -1)
		return (-1);
	return (0);
}

int			fill_params(const char **s, t_printf *params)
{
	char	*res;

	if (!*s || !params)
		return (-1);
	if (ft_strstr(*s, "hh"))
	{
		params->hh = 1;
		res = ft_deletestr((char *)*s, "hh");
		return (fill_params((const char**)&res, params));
	}
	if (ft_strchr(*s, 'h'))
	{
		params->h = 1;
		res = ft_deletestr((char *)*s, "h");
		return (fill_params((const char**)&res, params));
	}
	if (flags_j_z(*s, params) == -1)
		return (-1);
	ft_memdel((void **)s);
	return (0);
}
