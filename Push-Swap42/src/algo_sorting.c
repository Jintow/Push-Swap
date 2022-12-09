/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:55:36 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/09 17:57:42 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_categ_sorting(t_listi **lst, int piv, int low_piv, int max);
void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv);

void	left_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int	count;

	init_sorting(lb, la, low_piv);
	if (no_more_low_piv(*lb, i_piv, low_piv) && low_piv < 1)
		left_sorting(la, lb, i_piv, low_piv + 1);
	else if (no_more_piv(*lb, i_piv))
		left_sorting(la, lb, i_piv + 1, 0);
	ft_printf("\npiv : %d, low_piv : %d", i_piv, low_piv);

	count = count_elem(lb, i_piv, low_piv);
	if (count <= 3)
	{
		if (count > 0)
		{
			sort_three_lb(la, lb);
		}
		// if (low_piv < 1)
		// 	right_sorting(la, lb, i_piv, low_piv + 1); //+ possibilites de double rev_rot
		// else if (*lb)
		// 	left_sorting(la, lb, i_piv + 1, 0);
		// else
		// 	exit (0);
	}
	else
	{
		split_categ_sorting(lb, i_piv, low_piv, count);
		count_elem(lb, i_piv, low_piv);
		pivot_left(la, lb, i_piv, low_piv - 1);
		// right_sorting(la, lb, i_piv, low_piv - 1);
	}
}

// void	right_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
// {
// 	int	count;


// 	init_sorting_la(lb, la, low_piv);
// 	if (no_more_low_piv(*la, i_piv, low_piv) && low_piv < 1)
// 		left_sorting(la, lb, i_piv, low_piv + 1);
// 	// else if (no_more_piv(*lb, i_piv)) facultatif je pense car ca ne sera jamais sur la que la derniere sous-categ sera triee;
// 	// 	left_sorting(la, lb, i_piv + 1, 0);
// 	count = count_elem(*la, i_piv, low_piv);
// 	if (count <= 3)
// 	{
// 		sort_three(la, 'a');
// 		if (low_piv < 1)
// 			left_sorting(la, lb, i_piv, low_piv + 1)
// 		else if (*lb)
// 			left_sorting(la, lb, i_piv + 1, 0)
// 		else
// 			exit (0);
// 	}
// 	else if (count <= 6)
// 	else
// 	{
// 		split_categ_sorting(la, i_piv, low_piv, find_max_low_categ(la, i_piv, low_piv));
// 		pivot_right(lb, i_piv, low_piv - 1); //+possibilites de double rev_rot, a priori non!
// 		left_sorting(la, lb, i_piv, low_piv - 1); // attention aux conditions particulieres dans la;
// 	}
// }

// int	find_max_low_categ(t_listi *lst, int piv, int low_piv)
// {
// 	int	max;
	
// 	max = 0;
// 	while (la)
// 	{
// 		if (la->piv == piv && la->pos > max)
// 			max = la->pos;
// 		la = la->next;
// 	}
// 	return (max);
// }

void	split_categ_sorting(t_listi **lst, int piv, int low_piv, int max)
{
	int		pos_max;
	t_listi	*temp;

	pos_max = max / 2;
	if (max % 2 == 0)
		pos_max -= 1;
	temp = *lst;
	while (temp && temp->low_piv == low_piv)
	{
		if (temp->pos <= pos_max)
			temp->low_piv -= 1;
		else
			temp->pos -= pos_max;
		temp = temp->next;
	}
}

void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	while ((*lb) && (*lb)->low_piv <= low_piv + 1)
	{
		if ((*lb)->low_piv == low_piv)
		{
			push(la, lb, 'a');
			if ((*la)->nb_elem_categ <= 6 && (*la)->nbr > (*la)->next->nbr)
			{
				if ((*lb)->nbr < (*lb)->next->nbr)
					double_swap(la, lb);
				else
					swap(la, 'a');
			}
		}
		else if (!no_more_low_piv(*lb, piv, low_piv))
			rotate(lb, 'b');
		else
			break ;
	}
	dprintf(1, "OK\n");
	ft_printf("%d\n", ft_lstlast_loc(*lb)->nb_elem_categ);
	if (ft_lstlast_loc(*lb)->nb_elem_categ <= 4)
	{
		while (ft_lstlast_loc(*lb)->low_piv == low_piv + 1)
		{
			rev_rotate(lb, 'b');
			if ((*lb)->nbr < (*lb)->next->nbr && (*la)->nbr > (*la)->next->nbr)
				double_swap(la, lb);
		}
	}
}
