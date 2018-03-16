/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:41:30 by gduval            #+#    #+#             */
/*   Updated: 2017/03/16 14:41:31 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*check_width(char *string, t_printf *params)
{
	int		i;
	char	*tmp;
	char	*size;

	if (!string || !params)
		return (NULL);
	i = 0;
	tmp = NULL;
	while (string[i])
	{
		if (string[i] > '0' && string[i] <= '9')
		{
			params->width = ft_atoi_max(string + i);
			size = ft_itoa_basemax(params->width, 10);
			tmp = ft_deletestr(string, size);
			ft_memdel((void **)&string);
			ft_memdel((void **)&size);
			return (tmp);
		}
		i++;
	}
	return (string);
}

int			get_width(char *string, t_printf *params, va_list vl)
{
	if (!string)
		return (-1);
	if ((string = check_width((char *)string, params)) == NULL)
	{
		ft_memdel((void **)&string);
		return (-1);
	}
	if (fill_params((const char**)&string, params) == -1)
	{
		ft_memdel((void **)&string);
		return (-1);
	}
	else if (string)
	{
		ft_memdel((void **)&string);
	}
	return (0);
}
