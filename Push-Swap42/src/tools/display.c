/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:23:13 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 17:35:03 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_listi(t_listi *la, t_listi *lb)
{
	while (la || lb)
	{
		if (la)
		{
			ft_printf("%d\t([%d][%d][%d][%d])", la->nbr, la->piv, \
				la->low_piv, la->pos, la->nb_elem_categ);
			la = la->next;
		}
		else
			ft_printf("\t\t\t\t");
		if (lb)
		{
			ft_printf("\t");
			ft_printf("%d\t([%d][%d][%d][%d])", lb->nbr, lb->piv, \
				lb->low_piv, lb->pos, lb->nb_elem_categ);
			lb = lb->next;
		}
		ft_printf("\n");
	}
	ft_printf("-----------------\t------------------\n\t\ta\t\t\t\t\tb\t\n");
}
