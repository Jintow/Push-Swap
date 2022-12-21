/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab_piv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:12:54 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/19 18:55:00 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_malloc_tab(t_tab *tab, size_t size_pivot);

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
	init_malloc_tab(tab, size_pivot);
	tab->size_pivot = size_pivot;
	size_temp = (tab->size + 1) / 2;
	size_pivot = 0;
	tab->tab_pivot_ind[0] = 0;
	while (tab->size - size_temp >= 2)
	{
		tab->tab_pivot[size_pivot++] = tab->tab[tab->size - size_temp];
		tab->tab_pivot_ind[tab->size_pivot + 1 - size_pivot] = tab->size - \
			size_temp;
		size_temp = size_temp + (tab->size - size_temp + 1) / 2;
	}
	tab->tab_pivot_ind[size_pivot + 1] = tab->size - 1;
}

void	init_malloc_tab(t_tab *tab, size_t size_pivot)
{
	tab->tab_pivot = malloc(sizeof(int) * size_pivot);
	if (!tab->tab_pivot)
	{
		free(tab->tab);
		exit(EXIT_FAILURE);
	}
	tab->tab_pivot_ind = malloc(sizeof(int) * (size_pivot + 2));
	if (!tab->tab_pivot_ind)
	{
		free(tab->tab);
		free(tab->tab_pivot);
		exit(EXIT_FAILURE);
	}
}