/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:02:18 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/06 19:54:08 by jlitaudo         ###   ########.fr       */
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
		if (tab_g->tab[i] >= tab_d->tab[j])
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
	size_t	size_prev;

	size_temp = tab->size / 2;
	size_pivot = 0;
	ft_printf("%d\n", tab->size - size_temp);
	while (tab->size - size_temp >= 2)
	{
		size_temp = size_temp + (tab->size - size_temp) / 2;
		size_pivot++;
		ft_printf("%d\n", tab->size - size_temp);
	}
	tab->tab_pivot = malloc(sizeof(int) * size_pivot);
	tab->size_pivot = size_pivot;
	size_temp = tab->size / 2;
	size_pivot = 0;
	size_prev = size_temp;
	while (tab->size - size_temp >= 2)
	{
		tab->tab_pivot[size_pivot++] = tab->tab[size_temp - 1];
		ft_printf("\n pivot %d(N%d) = %d\n", size_pivot, size_temp, tab->tab[size_temp - 1]);
		size_prev = size_temp;
		size_temp = size_temp + (tab->size - size_temp) / 2;
	}
	// if (tab->size == 4 || tab->size == 5)
	// 	tab->tab_pivot[0] = tab->tab[tab->size - 3];
}
