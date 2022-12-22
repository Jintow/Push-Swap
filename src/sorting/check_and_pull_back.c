/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_pull_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:26:35 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/22 15:05:27 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checking_last_piv(t_listi *lb, int low_piv);

/*
	Function that recalls all the elements of a sub-list at the top.
	It checks in the same time if the recalled element car be directly
	pushed into list-A. In this case, it calls the reindexing function.
*/

void	check_and_pull_back_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	if (!(*lb) || !(*la))
		return ;
	if (checking_last_piv(*lb, low_piv))
		return ;
	while (ft_lstlast_loc(*lb)->low_piv == low_piv && \
		ft_lstlast_loc(*lb)->piv == piv)
	{
		rev_rotate(lb, 'b');
		if ((*lb)->pos == 0)
		{
			(*lb)->low_piv -= 20;
			push(la, lb, 'a');
			re_index_lb(lb, piv, low_piv, 0);
		}
		else if ((*lb)->nbr < (*lb)->next->nbr && (*lb)->nb_elem_categ <= 3)
			swap(lb, 'b');
	}
}

/*
	Function that recalls all the elements of a sub-list at the top.
	It checks in the same time if the recalled element is directly
	well placed in list-A. In this case, it calls the reindexing function.
*/

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
		re_index_la(la, low_piv);
		if ((*la)->nbr > (*la)->next->nbr && (*la)->nb_elem_categ <= 4)
		{
			if ((*lb)->nbr < (*lb)->next->nbr)
				double_swap(la, lb);
			else
				swap(la, 'a');
		}
	}
}

/*
	Function that prevent an infinite loop in the case of only one
	sub-list remaining elements in list-B.
*/

int	checking_last_piv(t_listi *lb, int low_piv)
{
	t_listi	*temp;

	temp = lb;
	while (temp && temp->low_piv == low_piv)
		temp = temp->next;
	if (!temp)
		return (1);
	return (0);
}
