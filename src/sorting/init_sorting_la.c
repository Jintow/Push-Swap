/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting_la.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:19:40 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/22 16:05:21 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cond_swap_lb(t_listi **lb);
void	sort_when_zero_second(t_listi **la, t_listi **lb, int piv, int low_piv);
void	sort_when_zero_first(t_listi **la, t_listi **lb, int piv, int low_piv);

/*
	Function that check if the next number is alrealdy well placed
	into list-A. In this case it will "reindex" the relative position
	of each remaining element of the current sub-list.
	Then if there 3 or less elements in the current sub-list the function will
	sort them.
*/

void	init_sorting_la(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	int		count;

	re_index_la(la, low_piv);
	count = count_elem_in_categ(la, piv, low_piv);
	if (count > 3 || count == 0)
		return ;
	else if (count == 2)
	{
		if (cond_swap_lb(lb))
			double_swap(la, lb);
		else
			swap(la, 'a');
		re_index_la(la, low_piv);
	}
	else if (count == 3)
		sort_when_zero_second(la, lb, piv, low_piv);
}

void	sort_when_zero_second(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	if ((*la)->next->pos == 0)
	{
		double_rotate(la, lb);
		if ((*la)->nbr > (*la)->next->nbr)
		{
			if (cond_swap_lb(lb))
				double_swap(la, lb);
			else
				swap(la, 'a');
		}
		double_rev_rotate(la, lb);
		if ((*la)->nbr > (*la)->next->nbr)
		{
			(*la)->low_piv -= 20;
			if (cond_swap_lb(lb))
				double_swap(la, lb);
			else
				swap(la, 'a');
			(*la)->pos -= 1;
		}
		re_index_la(la, low_piv);
	}
	else
		sort_when_zero_first(la, lb, piv, low_piv);
}

void	sort_when_zero_first(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	(*la)->low_piv -= 20;
	if ((*lb)->nbr < (*lb)->next->nbr)
		double_swap(la, lb);
	else
		swap(la, 'a');
	sort_when_zero_second(la, lb, piv, low_piv);
}

int	cond_swap_lb(t_listi **lb)
{
	if ((*lb)->pos < (*lb)->next->pos && (*lb)->low_piv == \
		(*lb)->next->low_piv && (*lb)->piv == ((*lb)->next->piv))
		return (1);
	return (0);
}
