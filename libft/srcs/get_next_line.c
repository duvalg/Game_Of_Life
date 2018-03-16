/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:49:00 by gduval            #+#    #+#             */
/*   Updated: 2017/07/31 10:42:39 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*strsub_clean(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (!(sub = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[len] = '\0';
	free(s);
	return (sub);
}

int				read_overtake(char **overtake, char *tmp, char **line, int ret)
{
	int i;
	int overtake_size;

	overtake_size = ft_strlen(*overtake);
	if (*overtake && overtake_size > 0 && ret == 0)
	{
		i = 0;
		if (!(tmp = (char *)ft_memalloc(overtake_size)))
			exit(0);
		while ((*overtake)[i] != '\0' && (*overtake)[i] != '\n')
		{
			tmp[i] = (*overtake)[i];
			i++;
		}
		i = ((*overtake)[i] == '\n') ? i + 1 : i;
		tmp[i] = '\0';
		if (!(*overtake = strsub_clean(*overtake, i, ft_strlen(*overtake) - i)))
			exit(0);
		*line = tmp;
		if ((*overtake[0]) == '\0')
			overtake = NULL;
		return (1);
	}
	return (0);
}

int				add_in_tmp(char *buff, char *tmp, char **line, char **overtake)
{
	int	i;

	i = -1;
	if (!(tmp = ft_memalloc(BUFF_SIZE + ft_strlen(*overtake) + 1)))
		exit(0);
	if (ft_strlen(*overtake))
	{
		buff = ft_strjoin(*overtake, buff);
		ft_strdel(overtake);
	}
	while (buff[++i] != '\n' && buff[i] != '\0')
		tmp[i] = buff[i];
	tmp[i] = '\0';
	*line = (!*line) ? ft_strnew(ft_strlen(tmp)) : *line;
	*line = ft_strjoin_free(*line, tmp, 1);
	ft_strdel(&tmp);
	if (buff[i] == '\n')
	{
		if (buff[i + 1])
			*overtake = strsub_clean(buff, i + 1, ft_strlen(buff) - i);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char	*overtake = NULL;

	if (fd < 0 || !line)
		return (-1);
	tmp = NULL;
	*line = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (add_in_tmp((char *)&buff, tmp, (char **)line, &overtake) == 1)
			return (1);
	}
	if (read_overtake(&overtake, tmp, line, ret) == 1)
		return (1);
	if (ret == -1)
		return (-1);
	else if (ret == 0 && ft_strlen(*line) > 0)
		return (1);
	return (ret == 0) ? 0 : 1;
}
