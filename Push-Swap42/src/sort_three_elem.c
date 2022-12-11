/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:06:33 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/11 10:41:57 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	t_listi	*temp;

	temp = *lb;
	rotate(lb, 'b');
	swap(lb, 'b');
	push(la, lb, 'a');
	// init_sorting(la, lb);
	rev_rotate(lb, 'b');
}
