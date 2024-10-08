/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_pilot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:21:20 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/24 15:26:45 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_or_three(t_listi **la, t_listi **lb);

/*
	Function that do the first sort of list-A elements.
	Each elements go to list-B in a way depending of its
	sub-list (list->piv & list->low_piv information); 
*/

void	sorting_pilot(t_listi **la, t_tab *tab)
{
	size_t	i;
	t_listi	*lb;

	lb = NULL;
	make_tab_piv(tab, la);
	add_infolst(la, tab);
	split_categ(la, tab->size_pivot);
	i = tab->size_pivot;
	while (i > 0)
	{
		if (i == tab->size_pivot)
			pivot(la, &lb, i);
		else
			pivot2(la, &lb, i);
		i--;
	}
	free(tab->tab);
	free(tab->tab_pivot);
	free(tab->tab_pivot_ind);
	sort_two_or_three(la, &lb);
	sorting_lb(la, &lb, 1, 0);
}

void	gate_away(t_listi **la, t_listi **lb)
{
	ft_lstclear_loc(la);
	ft_lstclear_loc(lb);
	exit (0);
}

/*
	Sorting of the remaining element (no more than 3) in list-A.
*/

void	sort_two_or_three(t_listi **la, t_listi **lb)
{
	if (lst_size_loc(*la) == 2 && *lb == NULL)
		swap(la, 'a');
	else
	{
		if ((*la)->pos == 0)
			rotate(la, 'a');
		else if ((*la)->next->pos == 0)
			rev_rotate(la, 'a');
		if ((*lb) == NULL && (*la)->pos == 1)
			swap(la, 'a');
	}
}
