/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:52:01 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/09 10:18:10 by jlitaudo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*elem2;
	t_list	*front_list;

	if (!lst || !f || !del)
		return (NULL);
	elem = ft_lstnew((*f)(lst->content));
	if (!elem)
		return (NULL);
	front_list = elem;
	lst = lst->next;
	while (lst)
	{
		elem2 = ft_lstnew((*f)(lst->content));
		if (!elem2)
			ft_lstclear(&front_list, del);
		elem->next = elem2;
		elem = elem->next;
		lst = lst->next;
	}
	return (front_list);
}
