/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_pull_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:26:35 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/12 20:27:20 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_and_pull_back_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	t_listi	*temp;

	if (!(*lb) || !(*la))
		return ;
	temp = *lb;
	while (temp && temp->low_piv == low_piv)
		temp = temp->next;
	if (!temp)
		return ;
	while (ft_lstlast_loc(*lb)->low_piv == low_piv && \
		ft_lstlast_loc(*lb)->piv == piv)
	{
		rev_rotate(lb, 'b');
		if ((*lb)->pos == 0)
		{
			(*lb)->low_piv -= 20;
			push(la, lb, 'a');
			check_andput_nb(lb, piv, low_piv, 0);
		}
		else if ((*lb)->nbr < (*lb)->next->nbr && (*lb)->nb_elem_categ <= 4)
			swap(lb, 'b');
	}
}

void	check_and_pull_back_la(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	t_listi	*temp;

	if (!(*la) || !(*lb))
		return ;
	while (ft_lstlast_loc(*la)->low_piv == low_piv && \
		ft_lstlast_loc(*la)->piv == piv)
	{
		temp = ft_lstlast_loc(*lb);
		if (temp->low_piv == low_piv + 1 && temp->piv == piv)
			double_rev_rotate(la, lb);
		else
			rev_rotate(la, 'a');
		if ((*la)->nbr > (*la)->next->nbr && (*la)->nb_elem_categ <= 4)
		{
			if ((*lb)->nbr < (*lb)->next->nbr && (*lb)->nb_elem_categ <= 5)
				double_swap(la, lb);
			else
				swap(la, 'a');
		}
	}
}
