/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:43:21 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/12 17:54:05 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_rot_push2(t_listi **la, t_listi **lb, int i_piv);
int	test_rev_rot(t_listi **la, t_listi **lb, int i_piv);
int	cond_swap_la2(t_listi **la);

void	pivot2(t_listi **la, t_listi **lb, int i_piv)
{
	static unsigned int	i;
	int					lst_size;

	if (!(*la))
		return ;
	lst_size = (int)lst_size_loc(*la);
	while (lst_size-- > 0)
	{
		i += test_rot_push2(la, lb, i_piv);
		i++;
		if (lst_size_loc(*la) == 2 || no_more_piv(*la, i_piv))
			break ;
	}
	i += test_rev_rot(la, lb, i_piv);
}

int	test_rot_push2(t_listi **la, t_listi **lb, int i_piv)
{
	int	i;

	i = 0;
	if ((*la)->piv == i_piv)
	{
		if ((*lb) && (*lb)->low_piv == 0 && (*lb)->piv == i_piv && \
			(*la)->low_piv == 1)
			while ((*lb)->low_piv == 0 && (*lb)->piv == i_piv)
				rotate(lb, 'b');
		push(lb, la, 'b');
	}
	else
	{
		if ((*lb) && (*lb)->low_piv == 0 && (*lb)->piv == i_piv)
			double_rotate(la, lb);
		else
			rotate(la, 'a');
	}
	return (i);
}

int	test_rev_rot(t_listi **la, t_listi **lb, int i_piv)
{
	int	i;

	i = 0;
	while (ft_lstlast_loc(*lb)->low_piv == 0)
	{
		if ((*lb) && (*lb)->next && (*lb)->nbr < (*lb)->next->nbr)
		{
			if (cond_swap_la2(la) && i_piv <= 2)
			{
				double_swap(la, lb);
				i++;
			}
			else if (i_piv <= 1)
			{
				swap(lb, 'b');
				i++;
			}
		}
		if (i_piv == 1 && (ft_lstlast_loc(*la))->pos == 0)
			rev_rotate(lb, 'b');
		else
			double_rev_rotate(la, lb);
		i++;
	}
	return (i);
}

int	cond_swap_la2(t_listi **la)
{
	if ((*la)->next->nbr < (*la)->nbr && (*la)->piv == (*la)->next->piv)
		return (1);
	return (0);
}