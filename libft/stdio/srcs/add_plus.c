/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:33:47 by gduval            #+#    #+#             */
/*   Updated: 2017/05/03 13:33:49 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_plus(char *str, t_printf *params)
{
	char	*tmp;

	if (!str || !params)
		return (NULL);
	if (params->plus == 1)
	{
		if (ft_atoi(str) >= 0)
		{
			tmp = ft_strjoin_free("+", str, 2);
			return (tmp);
		}
	}
	return (str);
}
