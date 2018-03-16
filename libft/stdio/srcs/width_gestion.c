/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:00:42 by gduval            #+#    #+#             */
/*   Updated: 2017/04/03 16:00:43 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*width_nb(char *str, char *width, t_printf *params)
{
	char	c;

	if (params->precision < 0 && GLOBAL->activate_precision == 1)
		params->width = params->precision * -1;
	if (ft_strlen(str) >= params->width)
		return (NULL);
	c = ((params->zero == 1 && params->minus == 0) \
	&& GLOBAL->activate_precision == 0) ? '0' : ' ';
	if (!(width = ft_strnew(params->width - ft_strlen(str))))
		return (NULL);
	ft_memset(width, c, params->width - ft_strlen(str));
	return (width);
}

char			*standard_width(char *str, char *width, t_printf *params)
{
	char	c;

	if (params->precision < 0 && GLOBAL->activate_precision == 1)
		params->width = params->precision * -1;
	if (ft_strlen(str) >= params->width)
		return (NULL);
	c = (params->zero == 1 && params->minus == 0) ? '0' : ' ';
	if (!(width = ft_strnew(params->width - ft_strlen(str))))
		return (NULL);
	ft_memset(width, c, params->width - ft_strlen(str));
	return (width);
}

char			*width_gestion(char *str, t_printf *params)
{
	char	c;
	char	*width;
	char	*ret;

	if (!ft_strchr("dDuUxXioO", GLOBAL->type))
	{
		if (!(width = standard_width(str, width, params)))
			return (str);
	}
	else if (!(width = width_nb(str, width, params)))
		return (str);
	params->width = -1;
	if (params->minus == 1)
		ret = ft_strjoin_free(str, width, 3);
	else
		ret = ft_strjoin_free(width, str, 3);
	if (ft_strchr("dDuUixX", GLOBAL->type) && params->minus == 0)
		ret = special_width(ret, params);
	if (params->blank == 1 && ret[0] == '0')
	{
		ret[0] = ' ';
		ret[1] = '0';
	}
	return (ret);
}
