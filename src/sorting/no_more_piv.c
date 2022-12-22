/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_more_piv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:27:03 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/22 14:34:59 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_more_piv(t_listi	*lst, int piv)
{
	while (lst)
	{
		if (lst->piv == piv)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	no_more_low_piv(t_listi	*lst, int piv, int low_piv)
{
	while (lst && lst->piv == piv)
	{
		if (lst->low_piv == low_piv)
			return (0);
		lst = lst->next;
	}
	return (1);
}
