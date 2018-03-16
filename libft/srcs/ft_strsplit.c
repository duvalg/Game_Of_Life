/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:45:13 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 15:25:33 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static	size_t	ft_tablsize(char const *s, char c)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			size++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (size);
}

static	char	**ft_filltabl(char const *s, char **str, char c)
{
	int			i;
	int			j;
	int			u;

	i = 0;
	j = 0;
	u = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			str[u] = ft_strsub(s, j, (i - j));
			u++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	str[u] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;

	if (s)
	{
		if (!(str = (char **)ft_memalloc(sizeof(char *) * \
		(ft_tablsize(s, c) + 1))))
			return (NULL);
		return (ft_filltabl(s, str, c));
	}
	return (NULL);
}
