/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:25:40 by gduval            #+#    #+#             */
/*   Updated: 2017/05/03 16:25:41 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_hash(char *str, t_printf *params)
{
	char *tmp;

	if (!str || !params)
		return (NULL);
	if (params->hash == 0 || !ft_strcmp(str, "0"))
		return (str);
	if (ft_strchr("xX", GLOBAL->type) && ft_atoi(str) == 0)
		return (str);
	if (GLOBAL->type == 'o' || GLOBAL->type == 'O')
		tmp = ft_strjoin_free("0", str, 2);
	else if (GLOBAL->type == 'x')
		tmp = ft_strjoin_free("0x", str, 2);
	else if (GLOBAL->type == 'X')
		tmp = ft_strjoin_free("0X", str, 2);
	return (tmp);
}
