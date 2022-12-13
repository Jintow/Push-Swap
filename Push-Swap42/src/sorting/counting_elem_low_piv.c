/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_elem_low_piv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:33:02 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/12 21:00:39 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_info_nbmax_categ(t_listi *temp, int piv, int low_piv, t_nb_elem nb);

int	count_elem_in_categ(t_listi	**lst, int piv, int low_piv)
{
	t_listi		*temp;
	t_nb_elem	nb_in_categ;

	nb_in_categ.i = 0;
	nb_in_categ.j = 0;
	nb_in_categ.k = 0;
	temp = *lst;
	while (temp && temp->piv == piv && temp->low_piv >= low_piv - 1 && \
		temp->low_piv <= low_piv + 1)
	{
		if (temp->low_piv == low_piv - 1)
			nb_in_categ.i += 1;
		else if (temp->low_piv == low_piv)
			nb_in_categ.j += 1;
		else
			nb_in_categ.k += 1;
		temp = temp->next;
	}
	temp = *lst;
	add_info_nbmax_categ(temp, piv, low_piv, nb_in_categ);
	return (nb_in_categ.j);
}

void	add_info_nbmax_categ(t_listi *temp, int piv, int low_piv, t_nb_elem nb)
{
	while (temp && temp->piv == piv && temp->low_piv >= low_piv - 1 && \
		temp->low_piv <= low_piv + 1)
	{
		if (temp->low_piv == low_piv - 1)
			temp->nb_elem_categ = nb.i;
		else if (temp->low_piv == low_piv)
			temp->nb_elem_categ = nb.j;
		else
			temp->nb_elem_categ = nb.k;
		temp = temp->next;
	}
}
