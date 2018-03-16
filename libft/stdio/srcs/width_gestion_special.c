/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_gestion_special.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:14:11 by gduval            #+#    #+#             */
/*   Updated: 2017/06/01 15:14:12 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*negative_width(char *str, t_printf *params)
{
	int		i;
	char	c;
	char	*s1;
	char	*s2;

	i = 0;
	c = ((params->zero == 1 && params->minus == 0) \
	&& GLOBAL->activate_precision == 0) ? '0' : ' ';
	while (str[i] && (str[i] == '-' || str[i] == c))
		i++;
	s2 = ft_strsub(str, i, ft_strlen(str) - i);
	s1 = ft_strsub(str, 0, i);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == '-')
			s1[i] = c;
		i++;
	}
	s1[0] = '-';
	s1 = ft_strjoin_free(s1, s2, 3);
	return (s1);
}

static char		*hexa_width(char *str, t_printf *params)
{
	char		*s1;
	char		*s2;
	int			i;

	i = 0;
	if (params->zero == 0 || params->hash == 0)
		return (str);
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] == 0)
		return (str);
	s2 = ft_strsub(str, i + 1, ft_strlen(str) - i);
	s1 = ft_strsub(str, 0, i - 1);
	s1 = (GLOBAL->type == 'x') ? ft_strjoin_free("0x", s1, 2) :\
	ft_strjoin_free("0X", s1, 2);
	s1 = ft_strjoin_free(s1, s2, 3);
	return (s1);
}

static char		*plus_width(char *str, t_printf *params)
{
	int		i;
	char	c;
	char	*s1;
	char	*s2;

	i = 0;
	c = ((params->zero == 1 && params->minus == 0) \
	&& GLOBAL->activate_precision == 0) ? '0' : ' ';
	while (str[i] && (str[i] == '+' || str[i] == c))
		i++;
	s2 = ft_strsub(str, i, ft_strlen(str) - i);
	s1 = ft_strsub(str, 0, i);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == '+')
			s1[i] = c;
		i++;
	}
	s1[0] = '+';
	s1 = ft_strjoin_free(s1, s2, 3);
	return (s1);
}

char			*special_width(char *str, t_printf *params)
{
	if (GLOBAL->type == 'x' || GLOBAL->type == 'X')
		str = hexa_width(str, params);
	else if (params->zero > 0 && ft_strchr(str, '-'))
		str = negative_width(str, params);
	else if (params->zero > 0 && ft_strchr(str, '+'))
		str = plus_width(str, params);
	return (str);
}
