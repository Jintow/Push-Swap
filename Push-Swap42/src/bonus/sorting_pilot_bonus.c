/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_pilot_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:21:20 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 20:08:46 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sort_two_or_three_bonus(t_listi **la, t_listi **lb);

void	sorting_pilot_bonus(t_listi **la, t_tab *tab)
{
	size_t		i;
	t_listi	*lb;

	lb = NULL;
	make_tab_piv(tab);
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
	sort_two_or_three_bonus(la, &lb);
	sorting_lb_bonus(la, &lb, 1, 0);
}

void	gate_away_bonus(t_listi **la, t_listi **lb, char *buffer)
{
	ft_lstclear_loc(la);
	ft_lstclear_loc(lb);
	execute_command(buffer, la, lb);
}

void	sort_two_or_three_bonus(t_listi **la, t_listi **lb)
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
