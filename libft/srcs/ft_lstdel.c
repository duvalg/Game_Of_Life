/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:42:31 by gduval            #+#    #+#             */
/*   Updated: 2016/11/21 17:22:10 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *alst;
	if (alst)
	{
		while (tmp)
		{
			next = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = next;
		}
		*alst = NULL;
	}
}
