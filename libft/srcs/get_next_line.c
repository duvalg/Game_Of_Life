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

static int	read_reste(char **reste, char **line, size_t len)
{
	int		i;
	int		end;
	char	tmp[len + 1];

	tmp[len] = '\0';
	end = 0;
	if (!(*line = ft_strnew(len)))
		return (-1);
	i = -1;
	while ((*reste)[++i] != '\n' && (*reste)[i] != '\0')
		(*line)[i] = (*reste)[i];
	if ((*reste)[i] == '\n')
	{
		end = 1;
		i++;
	}
	ft_bzero(tmp, len + 1);
	ft_strcpy(tmp, *reste + i);
	ft_bzero(*reste, len);
	ft_strcpy(*reste, tmp);
	if (end == 1)
		return (1);
	return (0);
}

static int	read_buff(char *buff, char **line, char **reste, size_t len)
{
	int		i;
	char	tmp[len + 1];

	ft_bzero(tmp, len + 1);
	i = -1;
	while (buff[++i] != '\n' && buff[i])
		tmp[i] = buff[i];
	if (!(*line))
	{
		if (!(*line = ft_strdup(tmp)))
			return (-1);
	}
	else
		*line = ft_strjoin_free(*line, tmp, 1);
	if (buff[i] == '\n')
	{
		if (!(*reste = ft_strnew(len - i)))
			return (-1);
		i++;
		ft_strcpy(*reste, buff + i);
		return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	int			success;
	char		buff[BUFF_SIZE + 1];
	static char	*reste = NULL;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	success = 0;
	ret = 0;
	if (ft_strlen(reste))
		if (read_reste(&reste, line, ft_strlen(reste)) == 1)
			return (1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((success = read_buff((char*)&buff, line, &reste, BUFF_SIZE)) == -1)
			return (-1);
		if (success == 1)
			return (1);
	}
	if (!ft_strlen(reste) && ret == 0 && !ft_strlen(*line))
		return (0);
	return (ret != -1) ? 1 : -1;
}
