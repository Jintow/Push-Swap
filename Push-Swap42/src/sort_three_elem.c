/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:06:33 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/12 19:01:49 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	t_listi	*temp;

	temp = *lb;
	rotate(lb, 'b');
	if ((*la)->nbr > (*la)->next->nbr)
		double_swap(la, lb);
	else
		swap(lb, 'b');
	push(la, lb, 'a');
	rev_rotate(lb, 'b');
}
