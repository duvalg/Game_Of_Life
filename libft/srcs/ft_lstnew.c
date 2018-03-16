/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:57:05 by gduval            #+#    #+#             */
/*   Updated: 2016/11/21 14:49:49 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, ft_strlen(content));
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
