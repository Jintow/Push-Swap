/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:55:36 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/22 16:13:05 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Sorting_lb and sorting_la functions are the heart of the algorythm process.
	They first check if there are elements that are alreay sorted.
	They will split any sub-list into 3 whenever it contains more than 3
	elemets. 
	They call each other to sort the splitted sub-lists until getting a sub-list
	with 3 elements or less.
	From the moment where no more elements of a sub-list exist, they'll sort the
	next "low-piv" of the same "piv" sub-list.
	If no more "low_piv" of a sub-list remains (when "low_piv" value outmod 1)
	"sorting_lb" begins to sort the next "piv" sub-list.
*/

void	sorting_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	int	count;

	if (*lb == NULL)
		gate_away(la, lb);
	init_sorting_lb(la, lb, piv, low_piv);
	check_and_pull_back_lb(la, lb, piv, low_piv);
	init_sorting_lb(la, lb, piv, low_piv);
	count = count_elem_in_categ(lb, piv, low_piv);
	if (low_piv > 1)
		sorting_lb(la, lb, piv + 1, 0);
	else if (count == 0)
	{
		if (ft_lstlast_loc(*la)->low_piv == low_piv + 1 \
			&& ft_lstlast_loc(*la)->piv == piv)
			sorting_la(la, lb, piv, low_piv);
		else
			sorting_lb(la, lb, piv, low_piv + 1);
	}
	else
	{
		split_categ_sorting(lb, piv, low_piv, count);
		count_elem_in_categ(lb, piv, low_piv - 1);
		pivot_lb(la, lb, piv, low_piv - 1);
		sorting_la(la, lb, piv, low_piv - 2);
	}
}

void	sorting_la(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	int	count;

	count = count_elem_in_categ(la, piv, low_piv);
	init_sorting_la(la, lb, piv, low_piv);
	count = count_elem_in_categ(la, piv, low_piv);
	if (count == 0 && ft_lstlast_loc(*la)->low_piv == low_piv + 1 \
		&& ft_lstlast_loc(*la)->piv == piv)
	{
		check_and_pull_back_la(la, lb, piv, low_piv + 1);
		re_index_la(la, low_piv + 1);
		sorting_la(la, lb, piv, low_piv + 1);
	}
	else if (count == 0)
		sorting_lb(la, lb, piv, low_piv);
	else
	{
		split_categ_sorting(la, piv, low_piv, count);
		count_elem_in_categ(la, piv, low_piv - 1);
		pivot_la(la, lb, piv, low_piv - 1);
		sorting_lb(la, lb, piv, low_piv - 2);
	}
}
