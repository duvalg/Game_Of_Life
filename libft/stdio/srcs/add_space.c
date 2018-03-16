/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:38:59 by gduval            #+#    #+#             */
/*   Updated: 2017/05/04 13:39:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_space(char *str, t_printf *params)
{
	char	*tmp;

	if (!str || !params)
		return (NULL);
	if (params->blank > 0 && !ft_strchr(str, '-'))
	{
		if (params->width == -1)
			return (str);
		tmp = ft_strjoin(" ", str);
		ft_memdel((void **)&str);
		return (tmp);
	}
	return (str);
}
