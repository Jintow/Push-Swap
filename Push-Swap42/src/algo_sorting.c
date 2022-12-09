/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:55:36 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/10 00:27:24 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_categ_sorting(t_listi **lst, int piv, int low_piv, int max);
void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv);

void	left_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	if (*lb == NULL)
	{
		ft_printf("\n");
		print_listi(*la, *lb);
		exit(0);
	}
	ft_printf("\npiv : %d, low_piv : %d\n", i_piv, low_piv);
	init_sorting(lb, la, i_piv, low_piv);
	if (no_more_low_piv(*lb, i_piv, low_piv) && low_piv < 1)
		left_sorting(la, lb, i_piv, low_piv + 1);
	else if (no_more_piv(*lb, i_piv))
		left_sorting(la, lb, i_piv + 1, 0);
	else
	{
		split_categ_sorting(lb, i_piv, low_piv, count_elem(lb, i_piv, low_piv));
		count_elem(lb, i_piv, low_piv);
		pivot_left(la, lb, i_piv, low_piv - 1);
		// ft_printf("nb_elem_categ%d\n", (*la)->nb_elem_categ);
		// right_sorting(la, lb, i_piv, low_piv - 1);
	}
}

// void	right_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
// {
// 	int	count;

// 	init_sorting_la(la, i_piv, low_piv);
// // mettre ici un check s'il reste des elem en fin de liste;
// 	count = count_elem(la, i_piv, low_piv);
// 	if (no_more_low_piv(*la, i_piv, low_piv))
// 		left_sorting(la, lb, i_piv, low_piv + 1);
// 	else
// 	{
// 		split_categ_sorting(la, i_piv, low_piv, count);
// 		pivot_right(lb, i_piv, low_piv - 1); //+possibilites de double rev_rot, a priori non!
// 		left_sorting(la, lb, i_piv, low_piv - 1); // attention aux conditions particulieres dans la;
// 	}
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
		if (max % 2 == 0)
		{
			if (temp->pos <= pos_max)
				temp->low_piv -= 1;
			else
				temp->pos -= pos_max;
		}
		else
		{
			if (temp->pos < pos_max)
				temp->low_piv -= 1;
			else
				temp->pos -= pos_max;
		}
		temp = temp->next;
	}
}

void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	while ((*lb) && (*lb)->low_piv <= low_piv + 1)
	{
		if (no_more_low_piv(*lb, piv, low_piv))
			break ;
		else if ((*lb)->low_piv == low_piv + 1)
		{
			if ((*la)->low_piv == low_piv && (*la)->pos >= (*la)->nb_elem_categ / 2)
				double_rotate(la, lb);
			else
				rotate(lb, 'b');
		}
		else
		{
			(*la)->low_piv -= 1;
			push(la, lb, 'a');
			if ((*la)->nbr > (*la)->next->nbr && (*la)->nb_elem_categ <= 8)
			{
				if ((*lb)->nbr < (*lb)->next->nbr)
					double_swap(la, lb);
				else
					swap(la, 'a');
			}
		}
	}
	// if (ft_lstlast_loc(*lb)->nb_elem_categ <= 4)
	// {
	// 	while (ft_lstlast_loc(*lb)->low_piv == low_piv + 1)
	// 	{
	// 		rev_rotate(lb, 'b');
	// 		if ((*lb)->nbr < (*lb)->next->nbr && (*la)->nbr > (*la)->next->nbr)
	// 			double_swap(la, lb);
	// 	}
	// }
}
