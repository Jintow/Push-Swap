/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:19:40 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/09 18:46:03 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sorting_la(t_listi **la, t_listi **lb, int low_piv)
{
	t_listi	*temp;

	check_andput_zero(lb, low_piv + 1);
	re_index_la(la);
	if (count_elem(la, ))
	temp = *la;
	if (temp && temp->pos == 0)
	{
		push(lst_to, lst_from, 'a');
		check_andput_zero(lst_from, low_piv);
		init_sorting(lst_from, lst_to, low_piv);
	}
	else if (temp && temp->next && temp->next->pos == 0)
	{
		swap(lst_from, 'b');
		push(lst_to, lst_from, 'a');
		check_andput_zero(lst_from, low_piv);
		init_sorting(lst_from, lst_to, low_piv);
	}
	else if (temp && temp->next && temp->next->next && temp->next->next->pos == 0 \
		&& (temp->pos == 1 || temp->next->pos == 1))
		sort_three_lb(lst_to, lst_from);
}