/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:03:33 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/07 19:57:06 by Teiki            ###   ########.fr       */
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
		ft_printf("sa ");
	else
		ft_printf("sb ");
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
	ft_printf("sss ");
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
		ft_printf("pa ");
	else
		ft_printf("pb ");
}

void	rotate(t_listi **list, char c)
{
	t_listi	*second;

	if (!(*list) || !(*list)->next)
		return ;
	second = (*list)->next;
	ft_lstadd_back_loc(list, *list);
	*list = second;
	if (c == 'a')
		ft_printf("ra ");
	else
		ft_printf("rb ");
}

void	double_rotate(t_listi **la, t_listi **lb)
{
	t_listi	*second;

	if ((*la) && (*la)->next)
	{
		second = (*la)->next;
		ft_lstadd_back_loc(la, *la);
		*la = second;
	}
	if ((*lb) && (*lb)->next)
	{
		second = (*lb)->next;
		ft_lstadd_back_loc(lb, *lb);
		*lb = second;
	}
	ft_printf("rr ");
}

void	rev_rotate(t_listi **list, char c)
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
	if (c == 'a')
		ft_printf("rra ");
	else
		ft_printf("rrb ");
}

void	double_rev_rotate2(t_listi **lb)
{
	t_listi	*last;
	t_listi	*temp;
	
	if ((*lb) && (*lb)->next)
	{
		temp = *lb;
		while (temp->next->next)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = *lb;
		*lb = last;
	}
	ft_printf("rrr ");
}

void	double_rev_rotate(t_listi **la, t_listi **lb)
{
	t_listi	*last;
	t_listi	*temp;

	if ((*la) && (*la)->next)
	{
		temp = *la;
		while (temp->next->next)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = *la;
		*la = last;	
	}
	double_rev_rotate2(lb);
}