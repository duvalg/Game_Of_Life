/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:12:08 by gduval            #+#    #+#             */
/*   Updated: 2016/11/25 13:36:40 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!(new = (*f)(lst)))
		return (NULL);
	tmp = new;
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			tmp->next = NULL;
			return (new);
		}
		if (!(tmp->next = (*f)(lst->next)))
			return (new);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
