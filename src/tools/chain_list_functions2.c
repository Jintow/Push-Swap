/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list_functions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:01:12 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 11:38:03 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone_loc(t_listi *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear_loc(t_listi **lst)
{
	t_listi	*p_lst;
	t_listi	*p_del_lst;

	if (!lst)
		return ;
	p_lst = *lst;
	while (p_lst)
	{
		p_del_lst = p_lst;
		p_lst = p_lst->next;
		p_del_lst->next = NULL;
		ft_lstdelone_loc(p_del_lst);
	}
	*lst = NULL;
}
