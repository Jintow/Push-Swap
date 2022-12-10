/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting_la.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:19:40 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/10 22:56:16 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cond_swap_lb(t_listi **lb, int piv, int low_piv);
void	sort_three_la(t_listi **la, t_listi **lb, int piv, int low_piv);
void	re_index_la(t_listi **la, int low_piv);

void	init_sorting_la(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	int		count;

	re_index_la(la, low_piv);
	count = count_elem(la, piv, low_piv); //faire attention a la fonction -> peut etre revoir son fonctionnement
	if (count > 3 || count == 0)
		return ;
	else if (count == 2)
	{
		if ((*lb)->pos < (*lb)->next->pos)
			double_swap(la, lb);
		else
			swap(la, 'a');
	}
	else if (count == 3)
		sort_three_la(la, lb, piv, low_piv);
}

void	sort_three_la(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	if ((*la)->next->pos == 0)
	{
		ft_printf("\nTHREE SORT!!\n");
		double_rotate(la, lb);
		if ((*la)->nbr > (*la)->next->nbr)
		{
			if (cond_swap_lb(lb, piv, low_piv))
				double_swap(la, lb);
			else
				swap(la, 'a');
		}
		if (cond_swap_lb(lb, piv, low_piv) && (*lb)->next->pos <= 2)
			swap(lb, 'b');
		double_rev_rotate(la, lb);
		if ((*la)->nbr > (*la)->next->nbr)
		{
			(*la)->low_piv -= 20;
			if (cond_swap_lb(lb, piv, low_piv))
				double_swap(la, lb);
			else
				swap(la, 'a');
		}
		re_index_la(la, low_piv);
	}
	else
	{
		(*la)->low_piv -= 20;
		if ((*lb)->pos < (*lb)->next->pos)
			double_swap(la, lb);
		else
			swap(la, 'a');
		sort_three_la(la, lb, piv, low_piv);
	}
}

void	re_index_la(t_listi **la, int low_piv)
{
	t_listi	*temp;

	temp = *la;
	while (temp->next->low_piv == low_piv)
		temp = temp->next;
	if (temp->pos == 0 && temp->low_piv == low_piv)
	{
		temp->low_piv -= 20;
		temp->piv -= 10;
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

int	cond_swap_lb(t_listi **lb, int piv, int low_piv)  // aurais pu etre simplifiee avec seulement une comparaison des nombres
{
	if ((*lb)->pos < (*lb)->next->pos && (*lb)->low_piv == \
				(*lb)->next->low_piv && (*lb)->piv == ((*lb)->next->piv))
		return (1);
	return (0);
}