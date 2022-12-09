/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:11:43 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/09 19:07:58 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_rot_push(t_listi **la, t_listi **lb, int i_piv);
int	test_swap(t_listi **la, t_listi **lb, int i_piv);
int	cond_swap_la(t_listi **la, int i_piv);

void	pivot(t_listi **la, t_listi **lb, int i_piv)
{
	static unsigned int	i;
	int					lst_size;

	if (!(*la))
		return ;
	lst_size = (int)lst_size_loc(*la);
	while (lst_size-- > 0)
	{
		i += test_swap(la, lb, i_piv);
		i += test_rot_push(la, lb, i_piv);
		i++;
		if (lst_size_loc(*la) == 2 || no_more_piv(*la, i_piv))
			break ;
	}
	if ((*lb) && (*lb)->low_piv == 1)
	{
		i++;
		rotate(lb, 'b');
	}
	ft_printf("\n\napres pivot (%d) (ci-dessous) : nb op tot: %d\n",i_piv, i);
}

int	test_swap(t_listi **la, t_listi **lb, int i_piv)
{
	if ((*lb) && (*lb)->next && (*lb)->nbr < (*lb)->next->nbr && \
		(*lb)->low_piv == (*lb)->next->low_piv)
	{	
		if (cond_swap_la(la, i_piv))
		{
			double_swap(la, lb);
			return (1);
		}
	}
	return (0);
}

int	test_rot_push(t_listi **la, t_listi **lb, int i_piv)
{
	int	i;

	i = 0;
	if ((*la)->piv == i_piv)
	{
		if ((*lb) && (*lb)->low_piv == 1 && (*lb)->piv == i_piv)
		{
			rotate(lb, 'b');
			i++;
		}
		push(lb, la, 'b');
	}
	else
	{
		if ((*lb) && (*lb)->low_piv == 1 && (*lb)->piv == i_piv)
			double_rotate(la, lb);
		else
			rotate(la, 'a');
	}
	return (i);
}

int	cond_swap_la(t_listi **la, int i_piv)
{
	if (((*la)->next->nbr < (*la)->nbr && (*la)->piv == (*la)->next->piv && \
		(*la)->next->low_piv == (*la)->low_piv && (*la)->low_piv == 1 && \
		(*la)->piv == i_piv) || \
		((*la)->next->nbr > (*la)->nbr && (*la)->piv == (*la)->next->piv && \
		(*la)->next->low_piv == (*la)->low_piv))
		return (1);
	return (0);
}

/*
Function that check if la can be swapped : 
If la < la next both of la and la->next belong 
to the same pivot category, the same low categoryexcept the current piot categ 
and low categ 1 (because low categ 1 will be rotated, so we want to keep the ß
smallest downside the biggest).
For all other cases, we want to wswap only if they belong to the same pivot 
categ and low_categ.
*/