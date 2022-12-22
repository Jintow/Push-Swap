/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_elem_low_piv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:33:02 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/22 15:55:09 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_info_nbmax_categ(t_listi *temp, int piv, int low_piv, t_nb_elem nb);

/*
	Function that count the number of element of a current sub-list.
	It can be called after the sorting init to know if there remains some 
	sub-list elements.
	It can be called also after a splitting where there are 3 sub-lists 
	for which it is needed to add information 
	(new number of elements of a sub-list);
*/

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

/*
	Function that add for each element of a sub-list set, the number of element
	in the corresponding sub-list.
*/

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
