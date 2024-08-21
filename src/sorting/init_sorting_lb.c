/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting_lb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:05:18 by jlitaudo          #+#    #+#             */
/*   Updated: 2024/08/20 15:22:43 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_one_lb(t_listi **la, t_listi **lb, int piv, int low_piv);
void	sort_two_lb(t_listi **la, t_listi **lb, int piv, int low_piv);
void	sort_three_lb(t_listi **la, t_listi **lb);

/*
	Function that check if the next number can be directly pushed
	into list-A. In this case it will "reindex" the relative position
	of each remaining element of the current sub-list.
	The process is called newly until the moment the next mumber is not
	easily reachable or there is no more element of the current sub-list.
*/

void	init_sorting_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	t_listi	*temp;

	if (no_more_low_piv(*lb, piv, low_piv))
		return ;
	re_index_lb(lb, piv, low_piv, 1);
	re_index_lb(lb, piv, low_piv, 0);
	temp = *lb;
	if (temp && temp->pos == 0 && temp->low_piv == low_piv)
		sort_one_lb(la, lb, piv, low_piv);
	else if (temp && temp->next && temp->next->pos == 0 && \
		temp->next->low_piv == low_piv)
		sort_two_lb(la, lb, piv, low_piv);
	// else if (temp && temp->next && temp->next->next && \
	// 	temp->next->next->pos == 0 && temp->nb_elem_categ <= 3 && \
	// 		temp->next->next->low_piv == low_piv)
	// {
	// 	sort_three_lb(la, lb);
	// 	init_sorting_lb(la, lb, piv, low_piv);
	// }
}

/*
	Put the next number to sort in list-A if it is at the top of list-B.
*/

void	sort_one_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	if ((*la)->nbr > (*la)->next->nbr)
		swap(la, 'a');
	push(la, lb, 'a');
	(*la)->low_piv -= 20;
	init_sorting_lb(la, lb, piv, low_piv);
}

/*
	Put the next number to sort in list-A if it is at the 
	second position of list-B.
*/

void	sort_two_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	if ((*la)->nbr > (*la)->next->nbr)
		double_swap(la, lb);
	else
		swap(lb, 'b');
	push(la, lb, 'a');
	(*la)->low_piv -= 20;
	init_sorting_lb(la, lb, piv, low_piv);
}

/*
	Put the next number to sort in list-A if it is at the 
	third position of list-B.
*/

void	sort_three_lb(t_listi **la, t_listi **lb)
{
	rotate(lb, 'b');
	if ((*la)->nbr > (*la)->next->nbr)
		double_swap(la, lb);
	else
		swap(lb, 'b');
	push(la, lb, 'a');
	rev_rotate(lb, 'b');
}
