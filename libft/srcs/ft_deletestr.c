/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:36:01 by gduval            #+#    #+#             */
/*   Updated: 2017/03/14 13:43:04 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	where_the_fuck_is_my_string(char *string, char *little)
{
	int		i;
	int		j;

	i = 0;
	while (string[i])
	{
		j = 0;
		while (string[i] == little[j] && little[j])
		{
			i++;
			j++;
		}
		if ((size_t)j == ft_strlen(little))
			return (i - j);
		i = (i - j) + 1;
	}
	return (-1);
}

char		*ft_deletestr(char *string, char *little)
{
	char	*s1;
	char	*s2;
	int		start;

	if (!(string) || !(little))
		return (0);
	if ((start = where_the_fuck_is_my_string(string, little)) == -1)
		return (0);
	s1 = ft_strsub(string, 0, start);
	s2 = ft_strsub(string, start + ft_strlen(little), ft_strlen(string));
	if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	else
		return (ft_strjoin_free(s1, s2, 3));
}
