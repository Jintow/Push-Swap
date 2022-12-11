/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_preparation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:14:32 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/11 17:37:55 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_listi *la, int piv);

void	make_tab_piv(t_tab	*tab)
{
	size_t	size_pivot;
	size_t	size_temp;

	size_temp = (tab->size + 1) / 2;
	size_pivot = 0;
	while (tab->size - size_temp >= 2)
	{
		size_temp = size_temp + (tab->size - size_temp + 1) / 2;
		size_pivot++;
	}
	tab->tab_pivot = malloc(sizeof(int) * size_pivot);
	tab->tab_pivot_ind = malloc(sizeof(int) * (size_pivot + 2));
	tab->size_pivot = size_pivot;
	size_temp = (tab->size + 1) / 2;
	size_pivot = 0;
	tab->tab_pivot_ind[0] = 0;
	while (tab->size - size_temp >= 2)
	{
		tab->tab_pivot[size_pivot++] = tab->tab[tab->size - size_temp];
		tab->tab_pivot_ind[tab->size_pivot + 1 - size_pivot] = tab->size - size_temp;
		// ft_printf("\n pivot %d(N%d) = %d\n", size_pivot, tab->size - size_temp + 1, tab->tab[tab->size - size_temp]);
		size_temp = size_temp + (tab->size - size_temp + 1) / 2;
	}
	tab->tab_pivot_ind[size_pivot + 1] = tab->size - 1;
}

void	add_infolst(t_listi **list, t_tab *tab)
{
	t_listi *lst;
	int		i;
	int		j;
	int		k;

	lst = *list;
	while (lst)
	{
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
		lst = lst->next;
	}
}

void	split_categ(t_listi **lst, int max_piv)
{
	int		pos_max;
	t_listi	*temp;
	
	while (max_piv >= 0)
	{
		pos_max = find_max(*lst, max_piv);
		temp = *lst;
		while (temp)
		{
			if (temp->piv == max_piv && pos_max > 4)
			{
				if (temp->pos > pos_max / 2)
				{
					temp->pos -= pos_max / 2;
					temp->low_piv = 1;
				}
				else
					temp->low_piv = 0;
			}
			else if (temp->piv == 1)
				temp->low_piv = 0;
			// temp->nb_elem_categ = 0;
			temp = temp->next;
		}
		max_piv--;
	}
}

int	find_max(t_listi *la, int piv)
{
	int	max;
	
	max = 0;
	while (la)
	{
		if (la->piv == piv && la->pos > max)
			max = la->pos;
		la = la->next;
	}
	return (max);
}
