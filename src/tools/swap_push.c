/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:03:33 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 19:11:41 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_listi **list, char c)
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
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	double_swap(t_listi **la, t_listi **lb)
{
	t_listi	*first;
	t_listi	*second;

	if ((*la) && (*la)->next)
	{
		first = *la;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*la = second;
	}
	if ((*lb) || (*lb)->next)
	{
		first = *lb;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*lb = second;
	}
	ft_printf("ss\n");
}

void	push(t_listi **list1, t_listi **list2, char c)
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
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}
