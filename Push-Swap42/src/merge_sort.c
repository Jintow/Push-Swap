/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:02:18 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/07 12:25:27 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_tab(t_tab *tab_g, t_tab *tab_d, t_tab *tab_tot);

int	*make_tab(char **str_tab, size_t size)
{
	int			*tab;
	size_t		i;

	tab = malloc(sizeof(int) * (size));
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(str_tab[i]);
		i++;
	}
	return (tab);
}

void	sort_merge(t_tab *tab)
{
	size_t	mid;
	t_tab	tab_g;
	t_tab	tab_d;

	if (tab->size > 1)
	{
		mid = tab->size / 2;
		tab_g.size = mid;
		tab_g.tab = tab->tab;
		tab_d.tab = &(tab->tab[mid]);
		tab_d.size = tab->size - mid;
		sort_merge(&tab_g);
		sort_merge(&tab_d);
		tab_g.tab = ft_intdup(tab_g.tab, tab_g.size);
		tab_d.tab = ft_intdup(tab_d.tab, tab_d.size);
		merge_tab(&tab_g, &tab_d, tab);
	}
}

void	merge_tab(t_tab *tab_g, t_tab *tab_d, t_tab *tab_tot)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < tab_g->size && j < tab_d->size)
	{
		if (tab_g->tab[i] <= tab_d->tab[j])
			tab_tot->tab[k++] = tab_g->tab[i++];
		else
			tab_tot->tab[k++] = tab_d->tab[j++];
	}
	while (j < tab_d->size)
		tab_tot->tab[k++] = tab_d->tab[j++];
	while (i < tab_g->size)
		tab_tot->tab[k++] = tab_g->tab[i++];
	free(tab_g->tab);
	free(tab_d->tab);
}

void	make_tab_piv(t_tab	*tab)
{
	size_t	size_pivot;
	size_t	size_temp;

	size_temp = (tab->size + 1) / 2;
	size_pivot = 0;
	ft_printf("%d\n", tab->size - size_temp);
	while (tab->size - size_temp >= 2)
	{
		size_temp = size_temp + (tab->size - size_temp + 1) / 2;
		size_pivot++;
		ft_printf("%d\n", tab->size - size_temp);
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
		ft_printf("\n pivot %d(N%d) = %d\n", size_pivot, tab->size - size_temp + 1, tab->tab[tab->size - size_temp]);
		size_temp = size_temp + (tab->size - size_temp + 1) / 2;
	}
	tab->tab_pivot_ind[size_pivot + 1] = tab->size - 1;
	// if (tab->size == 4 || tab->size == 5)
	// 	tab->tab_pivot[0] = tab->tab[tab->size - 3];
}

void	add_infolst(t_listi **list, t_tab *tab)
{
	t_listi *lst;
	int		i;
	int		j;
	int		k;

	lst = *list;
	k = -1;
	while (++k < (int)tab->size_pivot + 2)
		ft_printf("%d(%d') ", tab->tab_pivot_ind[k], k);
	ft_printf("\n\n");
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
		//ft_printf("nb : %d, i : %d, j : %d\n ", lst->nbr, i ,j);
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
