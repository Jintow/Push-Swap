/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_la.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:27:52 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/22 16:02:20 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_push_swap_la(t_listi **la, t_listi **lb, int low_piv);
void	rot_or_double_rot(t_listi **la, t_listi **lb, int low_piv);

/*
	Function that reproduces the pivot sorting in the previous function
	sorting_pilot.
	First sub-list to sort (low_piv - 1) is sent at the top of list-B.
	Second sub-list to sort (low_piv) is sent at the bottom of list-A.
	Third sub-list to sort (low_piv + 1) is sent at the bottom of list-B.
*/

void	pivot_la(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	while ((*la) && (*la)->low_piv <= low_piv + 1 && (*la)->low_piv >= \
		low_piv - 1 && (*la)->piv == piv)
	{
		if ((*la)->low_piv == low_piv)
			rot_or_double_rot(la, lb, low_piv);
		else
			rot_push_swap_la(la, lb, low_piv);
	}
	while ((*lb)->low_piv == low_piv + 1)
		rotate(lb, 'b');
}

void	rot_or_double_rot(t_listi **la, t_listi **lb, int low_piv)
{
	if ((*lb)->low_piv == low_piv + 1)
		double_rotate(la, lb);
	else
		rotate(la, 'a');
}

void	rot_push_swap_la(t_listi **la, t_listi **lb, int low_piv)
{
	if ((*lb)->low_piv == low_piv + 1 && (*la)->low_piv == low_piv - 1)
	{
		while ((*lb)->low_piv == low_piv + 1)
			rotate(lb, 'b');
	}
	push(lb, la, 'b');
	if ((*lb)->nbr < (*lb)->next->nbr && (*lb)->low_piv == \
		(*lb)->next->low_piv && (*lb)->nb_elem_categ <= 4)
	{
		if ((*la)->nbr > (*la)->next->nbr)
			double_swap(la, lb);
		else
			swap(lb, 'b');
	}
}
