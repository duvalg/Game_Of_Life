/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:45:22 by gduval            #+#    #+#             */
/*   Updated: 2017/05/31 10:45:23 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*insert_precision(char *str, char c, t_printf *params)
{
	int		i;
	char	*s1;
	char	*s2;

	if (!str || !params || !c)
		return (NULL);
	i = 0;
	while (str[i] && (str[i] == c || str[i] == '0'))
		i++;
	if (!(s2 = ft_strsub(str, i, ft_strlen(str) - i)))
		return (NULL);
	if (!(s1 = ft_strnew((params->precision - ft_strlen(s2)) + 1)))
		return (NULL);
	ft_memset(s1, '0', (params->precision - ft_strlen(s2)) + 1);
	s1[0] = c;
	s1 = ft_strjoin_free(s1, s2, 3);
	return (s1);
}

static char		*set_precision(char *str, char c, t_printf *params)
{
	char		*tmp;
	char		*add;
	int			size;

	if (!str || !params || !c)
		return (NULL);
	size = params->precision - (int)ft_strlen(str);
	if (ft_strchr(str, c) && size == 0)
		size++;
	if (size > 0)
	{
		if (!(add = ft_strnew(size)))
			return (NULL);
		add = ft_memset(add, '0', size);
		if (!(tmp = ft_strjoin(add, str)))
			return (NULL);
		ft_memdel((void **)&str);
		ft_memdel((void **)&add);
		if (ft_strchr(tmp, c))
			tmp = insert_precision(tmp, c, params);
		return (tmp);
	}
	return (str);
}

char			*nb_precision(char *str, t_printf *params)
{
	if (!str || !params)
		return (NULL);
	if (ft_strchr(str, '-'))
		str = set_precision(str, '-', params);
	else
		str = set_precision(str, '+', params);
	return (str);
}
