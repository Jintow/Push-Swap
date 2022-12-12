/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting_lb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:05:18 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/12 20:15:17 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_one_lb(t_listi **la, t_listi **lb, int piv, int low_piv);
void	sort_two_lb(t_listi **la, t_listi **lb, int piv, int low_piv);
void	sort_three_lb(t_listi **la, t_listi **lb, int piv, int low_piv);

void	init_sorting_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	t_listi	*temp;

	if (no_more_low_piv(*lb, piv, low_piv))
		return ;
	check_andput_nb(lb, piv, low_piv, 1);
	check_andput_nb(lb, piv, low_piv, 0);
	temp = *lb;
	if (temp && temp->pos == 0 && temp->low_piv == low_piv)
		sort_one_lb(la, lb, piv, low_piv);
	else if (temp && temp->next && temp->next->pos == 0 && \
		temp->next->low_piv == low_piv)
		sort_two_lb(la, lb, piv, low_piv);
	else if (temp && temp->next && temp->next->next && \
		temp->next->next->pos == 0 && temp->nb_elem_categ <= 3 && \
			temp->next->next->low_piv == low_piv)
	{
		sort_three_lb(la, lb, piv, low_piv);
		init_sorting_lb(la, lb, piv, low_piv);
	}
}

void	sort_one_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	if ((*la)->nbr > (*la)->next->nbr)
		swap(la, 'a');
	push(la, lb, 'a');
	(*la)->low_piv -= 20;
	init_sorting_lb(la, lb, piv, low_piv);
}

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

void	sort_three_lb(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	t_listi	*temp;

	temp = *lb;
	rotate(lb, 'b');
	if ((*la)->nbr > (*la)->next->nbr)
		double_swap(la, lb);
	else
		swap(lb, 'b');
	push(la, lb, 'a');
	rev_rotate(lb, 'b');
}
