/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_action_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:13:18 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 19:18:15 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap_bonus(t_listi **la, t_listi **lb)
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
}

void	double_rev_rotate2_bonus(t_listi **lb)
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
}

void	double_rev_rotate_bonus(t_listi **la, t_listi **lb)
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
	double_rev_rotate2_bonus(lb);
}

void	double_rotate_bonus(t_listi **la, t_listi **lb)
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
}
