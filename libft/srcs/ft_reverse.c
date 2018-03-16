/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:12:15 by gduval            #+#    #+#             */
/*   Updated: 2017/04/06 17:12:29 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*reverse_string(char *str)
{
	char	*reverse;
	int		i;
	int		j;

	reverse = ft_strnew(sizeof(char) * ft_strlen(str));
	i = ft_strlen(str) - 1;
	j = 0;
	while (i >= 0)
	{
		reverse[j] = str[i];
		i--;
		j++;
	}
	ft_strdel(&str);
	return (reverse);
}
