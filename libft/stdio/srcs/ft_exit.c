/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:09:36 by gduval            #+#    #+#             */
/*   Updated: 2017/04/22 16:09:37 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_exit(t_printf *params, t_global *global, va_list vl)
{
	ft_memdel((void **)&global);
	ft_memdel((void **)&params);
	va_end(vl);
}
