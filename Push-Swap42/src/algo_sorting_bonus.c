/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:55:36 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 18:19:04 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_lb(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int		count;
	char	buffer[1000000];

	buffer = read(0, buffer, 1000000);
	if (*lb == NULL)
		gate_away(la, lb, buffer);
	init_sorting_lb(la, lb, i_piv, low_piv);
	check_and_pull_back_lb(la, lb, i_piv, low_piv);
	init_sorting_lb(la, lb, i_piv, low_piv);
	count = count_elem_in_categ(lb, i_piv, low_piv);
	if (low_piv > 1)
		sorting_lb(la, lb, i_piv + 1, 0);
	else if (count == 0)
	{
		if (ft_lstlast_loc(*la)->low_piv == low_piv + 1 \
			&& ft_lstlast_loc(*la)->piv == i_piv)
			sorting_la(la, lb, i_piv, low_piv);
		else
			sorting_lb(la, lb, i_piv, low_piv + 1);
	}
	else
	{
		split_categ_sorting(lb, i_piv, low_piv, count);
		count_elem_in_categ(lb, i_piv, low_piv - 1);
		pivot_lb(la, lb, i_piv, low_piv - 1);
		sorting_la(la, lb, i_piv, low_piv - 2);
	}
}

void	sorting_la(t_listi **la, t_listi **lb, int i_piv, int low_piv)
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
		sorting_la(la, lb, i_piv, low_piv + 1);
	}
	else if (count == 0)
		sorting_lb(la, lb, i_piv, low_piv);
	else
	{
		split_categ_sorting(la, i_piv, low_piv, count);
		count_elem_in_categ(la, i_piv, low_piv - 1);
		pivot_la(la, lb, i_piv, low_piv - 1);
		sorting_lb(la, lb, i_piv, low_piv - 2);
	}
}
