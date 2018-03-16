/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:08:33 by gduval            #+#    #+#             */
/*   Updated: 2017/04/04 15:08:34 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_global	*init_global(t_global *global)
{
	if (!(global = ft_memalloc(sizeof(t_global))))
		exit(0);
	global->i = 0;
	global->count = 0;
	global->max_count = 0;
	global->count_letters = 0;
	global->activate_precision = 0;
	global->type = '\0';
	return (global);
}

void		init_struct(t_printf *params, t_global *global)
{
	params->h = 0;
	params->hh = 0;
	params->l = 0;
	params->ll = 0;
	params->j = 0;
	params->z = 0;
	params->hash = 0;
	params->zero = 0;
	params->minus = 0;
	params->plus = 0;
	params->blank = 0;
	params->width = 0;
	params->precision = -1;
	params->global = global;
}
