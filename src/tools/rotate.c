/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:51:01 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 19:11:25 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_listi **list, char c)
{
	t_listi	*second;

	if (!(*list) || !(*list)->next)
		return ;
	second = (*list)->next;
	ft_lstadd_back_loc(list, *list);
	*list = second;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
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
	ft_printf("rr\n");
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
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
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
	ft_printf("rrr\n");
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
