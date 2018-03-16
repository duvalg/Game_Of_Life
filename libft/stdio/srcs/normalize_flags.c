/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:23:40 by gduval            #+#    #+#             */
/*   Updated: 2017/05/31 10:32:10 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	normalize_flags(t_printf *params)
{
	if (GLOBAL->type == 'c' && params->l == 1)
	{
		GLOBAL->type = 'C';
		params->l = 0;
	}
	if (GLOBAL->type == 's' && params->l == 1)
	{
		GLOBAL->type = 'S';
		params->l = 0;
	}
}
