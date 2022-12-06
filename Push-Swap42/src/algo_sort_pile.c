/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:59:51 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/06 20:06:03 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_maxmin(t_listi **lst)
{
	t_listi *list;
	
	list = *lst;
	list->min = list->nbr;
	list->max = list->nbr;
	list = list->next;
	while (list)
	{
		if (list->nbr > list->max)
			list->max =lit./
	}


}
void	begin_sort(t_listi **la, t_listi **lb, t_tab tab)
{
	
}

void	pre_sort(t_listi **lst)
{
	int	first;
	int	second;
	int	third;
	
	if (lst_size_loc(*lst) == 2)
		if ((*lst)->next->nbr > (*lst)->nbr)
			swap(la);
	else if(lst_size_loc(*lst) == 3)
	{
		first = (*lst)->nbr;
		second = (*lst)->next->nbr;
		third = (*lst)->next->next->nbr;
		if (first > second && (first != third))
			pre_sort1(first, second, third, lst);
		else if (first < second && first < third)
			rotate(lst);
		else if(first < second)
			pre_sort2(first, second, third, lst);
	}
}

void	pre_sort1(int first, int second, int third, t_listi **lst)
{
	if (second < third)
	{
		swap(lst);
		rotate(lst);
	}
	else if ( second > third)
		rev_rotate(lst);
}

void	pre_sort2(int first, int second, int third, t_listi **lst)
{
	if (second >= third)
		rotate(lst);
	else if (third > second)
	{
		swap(lst);
		rev_rotate(lst);
	}
	else if( second == third)
		rev_rotate(lst);
}