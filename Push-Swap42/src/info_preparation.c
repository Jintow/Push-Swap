/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_preparation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:14:32 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/12 19:07:35 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_relative_position(t_listi *lst, t_tab *tab);

void	add_infolst(t_listi **list, t_tab *tab)
{
	t_listi	*lst;
	int		i;
	int		j;

	lst = *list;
	while (lst)
	{
		add_relative_position(lst, tab);
		lst = lst->next;
	}
}

void	add_relative_position(t_listi *lst, t_tab *tab)
{
	int	i;
	int	j;

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
