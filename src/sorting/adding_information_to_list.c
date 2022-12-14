/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_information_to_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:14:32 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/22 14:07:17 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_relative_position(t_listi *lst, t_tab *tab);

/*
	Function that add information to each element of the list.
*/

void	add_infolst(t_listi **list, t_tab *tab)
{
	t_listi	*lst;

	lst = *list;
	while (lst)
	{
		add_relative_position(lst, tab);
		lst = lst->next;
	}
}

/*
	Function that add the position of each number among its
	sub list (list->piv information).
	A sub-list correspond to all the number between two pivots number.
	The pivot of each sub-list is then the highest number of this sub-list,
	so the one with a position (index) of 0 in this sub-list;
*/

void	add_relative_position(t_listi *lst, t_tab *tab)
{
	int		i;
	size_t	j;

	i = 0;
	while (tab->tab[i] != lst->nbr)
		i++;
	j = 0;
	while (tab->tab_pivot_ind[j] < i)
		j++;
	if (tab->tab_pivot_ind[j] == i && j != tab->size_pivot + 1)
		j++;
	if (i == 0)
	{
		lst->piv = 0;
		lst->pos = 0;
	}
	else
	{
		lst->pos = i - tab->tab_pivot_ind[j - 1];
		lst->piv = j - 1;
	}
}
