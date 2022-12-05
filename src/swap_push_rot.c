/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:03:33 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/05 13:03:41 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_listi **list)
{
	t_listi	*first;
	t_listi	*second;

	if (!(*list) || !(*list)->next)
		return ;
	first = *list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	push(t_listi **list1, t_listi **list2)
{
	t_listi	*temp;

	if (!(*list2))
		return ;
	if (!(*list1))
	{
		*list1 = *list2;
		*list2 = (*list2)->next;
		(*list1)->next = NULL;
	}
	else
	{
		temp = (*list2)->next;
		ft_lstadd_front_loc(list1, *list2);
		*list2 = temp;
	}
}

void	rotate(t_listi **list)
{
	t_listi	*second;

	if (!(*list) || !(*list)->next)
		return ;
	second = (*list)->next;
	ft_lstadd_back_loc(list, *list);
	*list = second;
}

void	rev_rotate(t_listi **list)
{
	t_listi	*last;
	t_listi	*temp;

	if (!(*list) || !(*list)->next)
		return ;
	temp = *list;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *list;
	*list = last;
}
