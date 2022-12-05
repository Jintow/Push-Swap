/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:29:03 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/09 14:29:27 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p_lst;
	t_list	*p_del_lst;

	if (!lst || !del)
		return ;
	p_lst = *lst;
	while (p_lst)
	{
		p_del_lst = p_lst;
		p_lst = p_lst->next;
		p_del_lst->next = NULL;
		ft_lstdelone(p_del_lst, del);
	}
	*lst = NULL;
}
