/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:06:33 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/09 16:04:33 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_lb(t_listi **la, t_listi **lb)
{
	t_listi	*temp;

	temp = *lb;
	if (temp->next->pos == 1)
	{
		rotate(lb, 'b');
		swap(lb, 'b');
		push(la, lb, 'a');
		push(la, lb, 'a');
		rev_rotate(lb, 'b');
		if ((*lb)->pos == 2)
			push(la, lb, 'a');
	}
	else
	{
		rotate(lb, 'b');
		swap(lb, 'b');
		push(la, lb, 'a');
		rev_rotate(lb, 'b');
		push(la, lb, 'a');
		if ((*lb)->pos == 2)
			push(la, lb, 'a');
	}
}

void	sort_three_la(t_listi **la, t_listi **lb) // peut-etre inutile finalement
{
	t_listi	*temp;
	
	temp = *la;
	if (temp->next->pos == 1)
	{
		swap(la, 'a');
		rotate(la, 'a');
		swap(la, 'a');
		rev_rotate(la, 'a');
		swap(la, 'a');
	}
	else
	{
		swap(la, 'a');
		rotate(la, 'a');
		swap(la, 'b');
		rev_rotate(la, 'b');
	}
}