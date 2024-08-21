/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_categ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:15:39 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/22 14:07:30 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_listi *la, int piv);

/*
	Function that split each sub-list previously created (except the 1st one)
	into 2 (list->low_piv information).
	The relative position of each element is recalculated among those
	new sub lists;
*/

void	split_categ(t_listi **lst, int max_piv)
{
	int		pos_max;
	t_listi	*temp;

	while (max_piv >= 1)
	{
		pos_max = find_max(*lst, max_piv);
		temp = *lst;
		while (temp)
		{
			if (temp->piv == max_piv)
			{
				if (temp->pos > pos_max / 2)
				{
					temp->pos -= pos_max / 2;
					temp->low_piv = 1;
				}
				else
					temp->low_piv = 0;
			}
			temp = temp->next;
		}
		max_piv--;
	}
}

int	find_max(t_listi *la, int piv)
{
	int	max;

	max = 0;
	while (la)
	{
		if (la->piv == piv && la->pos > max)
			max = la->pos;
		la = la->next;
	}
	return (max);
}
