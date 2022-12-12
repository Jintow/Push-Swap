/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_indexing_la.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:22:42 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/12 19:23:08 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_index_la(t_listi **la, int low_piv)
{
	t_listi	*temp;

	temp = *la;
	while (temp->next->low_piv == low_piv)
		temp = temp->next;
	if (temp->pos == 0 && temp->low_piv == low_piv)
	{
		temp->low_piv -= 20;
		temp = *la;
		while (temp->low_piv == low_piv)
		{
			temp->pos--;
			temp = temp->next;
		}
		re_index_la(la, low_piv);
	}
	else
		return ;
}
