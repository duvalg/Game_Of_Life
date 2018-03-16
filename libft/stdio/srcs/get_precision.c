/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:21:09 by gduval            #+#    #+#             */
/*   Updated: 2017/03/31 11:21:10 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		last_checks(char *string)
{
	if (!ft_strchr(string, '.'))
		return (0);
	return (-1);
}

static char		*create_precision_string(char *string)
{
	int		size;
	int		i;

	i = 0;
	while (string[i] != '.' && string[i])
		i++;
	if (string[i] == '\0')
		return (NULL);
	i++;
	size = 0;
	while (string[i] && string[i] >= '0' && string[i] <= '9')
	{
		i++;
		size++;
	}
	size++;
	return (ft_strsub(string, i - (size), size));
}

char			*delete_precision(char *string, t_printf *params)
{
	char	*tmp;
	char	*join;

	join = create_precision_string(string);
	if (!join)
	{
		ft_memdel((void **)&join);
		return (string);
	}
	tmp = ft_deletestr(string, join);
	ft_memdel((void **)&join);
	ft_strdel(&string);
	if (last_checks(tmp))
		return (NULL);
	return (tmp);
}

int				get_precision(char *string, t_printf *params)
{
	int		i;

	if (!string || !params)
		return (-1);
	if (!ft_strchr(string, '.'))
		return (0);
	i = 0;
	while (string[i] != '.')
		i++;
	params->precision = ft_atoi(string + (i + 1));
	GLOBAL->activate_precision = 1;
	return (0);
}
