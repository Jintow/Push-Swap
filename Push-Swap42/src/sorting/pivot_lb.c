/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_lb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:37:32 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 16:54:42 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_push_swap_lb(t_listi **la, t_listi **lb, int low_piv);

void	pivot_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	while ((*lb) && (*lb)->low_piv <= low_piv + 1 && (*lb)->piv == piv)
	{
		if ((*lb)->low_piv == low_piv + 1)
		{
			if ((*la)->low_piv == low_piv)
				double_rotate(la, lb);
			else if (no_more_low_piv(*lb, piv, low_piv) && \
				no_more_low_piv(*lb, piv, low_piv - 1))
				break ;
			else
				rotate(lb, 'b');
		}
		else
			rot_push_swap_lb(la, lb, low_piv);
	}
	while ((*la)->low_piv == low_piv)
		rotate(la, 'a');
}

void	rot_push_swap_lb(t_listi **la, t_listi **lb, int low_piv)
{
	if ((*la)->low_piv == low_piv && (*lb)->low_piv == low_piv - 1)
	{
		while ((*la)->low_piv == low_piv)
			rotate(la, 'a');
	}
	push(la, lb, 'a');
	if ((*la)->nbr > (*la)->next->nbr && (*la)->nb_elem_categ <= 5)
	{
		if ((*lb)->nbr < (*lb)->next->nbr)
			double_swap(la, lb);
		else
			swap(la, 'a');
	}
}
