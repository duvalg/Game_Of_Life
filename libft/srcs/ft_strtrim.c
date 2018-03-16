/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:56:23 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 15:43:21 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_start(const char *s)
{
	int		start;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	return (start);
}

static int	ft_end(const char *s)
{
	int		end;

	end = ft_strlen((char *)s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	return (end < 0) ? ft_strlen(s) : end;
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	if (s)
	{
		start = ft_start(s);
		end = ft_end(s);
		return (ft_strsub(s, start, end - start + 1));
	}
	return (NULL);
}
