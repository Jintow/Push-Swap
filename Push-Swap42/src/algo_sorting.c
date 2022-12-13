/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:55:36 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 15:37:05 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv);
void	pivot_right(t_listi **la, t_listi **lb, int piv, int low_piv);
void	right_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv);

void	left_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int	count;

	if (*lb == NULL)
		gate_away(la, lb);
	init_sorting_lb(la, lb, i_piv, low_piv);
	check_and_pull_back_lb(la, lb, i_piv, low_piv);
	init_sorting_lb(la, lb, i_piv, low_piv);
	count = count_elem_in_categ(lb, i_piv, low_piv);
	if (low_piv > 1)
		left_sorting(la, lb, i_piv + 1, 0);
	else if (count == 0)
	{
		if (ft_lstlast_loc(*la)->low_piv == low_piv + 1 \
			&& ft_lstlast_loc(*la)->piv == i_piv)
			right_sorting(la, lb, i_piv, low_piv);
		else
			left_sorting(la, lb, i_piv, low_piv + 1);
	}
	else
	{
		split_categ_sorting(lb, i_piv, low_piv, count);
		count_elem_in_categ(lb, i_piv, low_piv - 1);
		pivot_left(la, lb, i_piv, low_piv - 1);
		right_sorting(la, lb, i_piv, low_piv - 2);
	}
}

void	right_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int	count;

	count = count_elem_in_categ(la, i_piv, low_piv);
	init_sorting_la(la, lb, i_piv, low_piv);
	count = count_elem_in_categ(la, i_piv, low_piv);
	if (count == 0 && ft_lstlast_loc(*la)->low_piv == low_piv + 1 \
		&& ft_lstlast_loc(*la)->piv == i_piv)
	{
		check_and_pull_back_la(la, lb, i_piv, low_piv + 1);
		re_index_la(la, low_piv + 1);
		right_sorting(la, lb, i_piv, low_piv + 1);
	}
	else if (count == 0)
		left_sorting(la, lb, i_piv, low_piv);
	else
	{
		split_categ_sorting(la, i_piv, low_piv, count);
		count_elem_in_categ(la, i_piv, low_piv - 1);
		pivot_right(la, lb, i_piv, low_piv - 1);
		left_sorting(la, lb, i_piv, low_piv - 2);
	}
}

void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	while ((*lb) && (*lb)->low_piv <= low_piv + 1 && (*lb)->piv == piv)
	{
		if ((*lb)->low_piv == low_piv + 1)
		{
			if ((*la)->low_piv == low_piv)
				double_rotate(la, lb);
			else if (no_more_low_piv(*lb, piv, low_piv) && \
				no_more_low_piv(*lb, piv, low_piv - 1))
				break ;
			else
				rotate(lb, 'b');
		}
		else
		{
			if ((*la)->low_piv == low_piv && (*lb)->low_piv == low_piv - 1)
			{
				while ((*la)->low_piv == low_piv)
					rotate(la, 'a');
			}
			push(la, lb, 'a');
			if ((*la)->nbr > (*la)->next->nbr && (*la)->nb_elem_categ <= 5)
			{
				if ((*lb)->nbr < (*lb)->next->nbr)
					double_swap(la, lb);
				else
					swap(la, 'a');
			}
		}
	}
	while ((*la)->low_piv == low_piv)
		rotate(la, 'a');
}

void	pivot_right(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	while ((*la) && (*la)->low_piv <= low_piv + 1 && (*la)->low_piv >= \
		low_piv - 1 && (*la)->piv == piv)
	{
		if ((*la)->low_piv == low_piv)
		{
			if ((*lb)->low_piv == low_piv + 1)
				double_rotate(la, lb);
			else
				rotate(la, 'a');
		}
		else
		{
			if ((*lb)->low_piv == low_piv + 1 && (*la)->low_piv == low_piv - 1)
			{
				while ((*lb)->low_piv == low_piv + 1)
					rotate(lb, 'b');
			}
			push(lb, la, 'b');
			if ((*lb)->nbr < (*lb)->next->nbr && (*lb)->low_piv == \
				(*lb)->next->low_piv && (*lb)->nb_elem_categ <= 5)
			{
				if ((*la)->nbr > (*la)->next->nbr)
					double_swap(la, lb);
				else
					swap(lb, 'b');
			}
		}
	}
	while ((*lb)->low_piv == low_piv + 1)
		rotate(lb, 'b');
}
