/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:32:02 by gduval            #+#    #+#             */
/*   Updated: 2017/06/07 14:21:48 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	is_a_type(char c)
{
	if (!c)
		return ('\0');
	if (c == 's' || c == 'S')
		return (c);
	else if (c == 'd' || c == 'D')
		return (c);
	else if (c == 'o' || c == 'O')
		return (c);
	else if (c == 'u' || c == 'U')
		return (c);
	else if (c == 'x' || c == 'X')
		return (c);
	else if (c == 'c' || c == 'C')
		return (c);
	else if (c == 'p')
		return (c);
	else if (c == 'i')
		return (c);
	else if (!ft_strchr("0123456789hljz.#-+sSpdDioOuUxXcC ", c))
		return (c);
	return ('\0');
}
