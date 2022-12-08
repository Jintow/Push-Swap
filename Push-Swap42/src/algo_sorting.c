/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:55:36 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/09 00:22:27 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	left_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int	count;
	int	max_pos;

	count = count_elem(*lb, i_piv, low_piv);
	if (count <= 3)
	{
		check_sort + pre_sort;
		sort_three(lb, 'b');
		if (low_piv < 1)
			right_sorting(la, lb, i_piv, low_piv + 1)
		else if (*lb)
			left_sorting(la, lb, i_piv + 1, 0)
		else
			exit (0);
	}
	else if (count <= 6)
	else
	{
		split_categ_sorting(lb, i_piv, low_piv, find_max_low_categ(lb, i_piv, low_piv));
		pivot_left(lb, i_piv, low_piv + 1);
		right_sorting(la, lb, i_piv, low_piv + 1);
	}
}

void	right_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int	count;

	check_sort + pre sort;
	count = count_elem(*lb, i_piv, low_piv);
	if (count <= 3)
	{
		sort_three(la, 'a');
		if (low_piv < 1)
			left_sorting(la, lb, i_piv, low_piv + 1)
		else if (*lb)
			left_sorting(la, lb, i_piv + 1, 0)
		else
			exit (0);
	}
	else if (count <= 6)
	else
	{
		split_categ_sorting(la, i_piv, low_piv, find_max_low_categ(la, i_piv, low_piv));
		pivot_right(lb, i_piv, low_piv + 1);
		left_sorting(la, lb, i_piv, low_piv + 1);
	}
}