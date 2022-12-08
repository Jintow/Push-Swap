/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:43:21 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/08 15:10:45 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_swap2(t_listi **la, t_listi **lb, int i_piv);
int	test_rot_swap2(t_listi **la, t_listi **lb, int i_piv);
int	test_rev_rot(t_listi **la, t_listi **lb, int i_piv);

void	pivot2(t_listi **la, t_listi **lb, int i_piv)
{
	static unsigned int	i;
	int			lst_size;

	if (!(*la))
		return ;
	lst_size = (int)lst_size_loc(*la);
	while (lst_size-- > 0)
	{
		i += test_swap2(la, lb, i_piv);
		i += test_rot_swap2(la, lb, i_piv);
		i++;
		if (lst_size_loc(*la) == 2 || no_more_piv(*la, i_piv))
			break;
	}
	i += test_rev_rot(la, lb, i_piv);
	ft_printf("\n%d : lst_size\n", lst_size);
	ft_printf("\n\napres pivot (%d) (ci-dessous) : nb op tot: %d\n",i_piv, i);
}

int	test_swap2(t_listi **la, t_listi **lb, int i_piv)
{
	int i;

	i = 0;
	if ((*lb) && (*lb)->next && (*lb)->nbr > (*lb)->next->nbr && (*lb)->low_piv == (*lb)->next->low_piv)
	{
		if ((*la)->next->nbr > (*la)->nbr && (*la)->next->low_piv == (*la)->low_piv && (*la)->piv == (*la)->next->piv && !((*la)->piv == i_piv && (*la)->low_piv == 1))
			double_swap(la, lb);
		else 
			swap(lb, 'b');
		i++;
	}
	if ((*la)->next->nbr > (*la)->nbr && (*la)->next->piv == (*la)->piv)
	{
		swap(la, 'a');
		i++;
	}
	return (i);
}

int	test_rot_swap2(t_listi **la, t_listi **lb, int i_piv)
{
	int	i;
	
	i = 0;
	if ((*la)->piv == i_piv)
	{
		if ((*lb) && (*lb)->low_piv == 0 && (*lb)->piv == i_piv)
		{
			rotate(lb, 'b');
			i++;
		}
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
		if ((*lb) && (*lb)->next && (*lb)->nbr > (*lb)->next->nbr)
		{
			if ((*la)->nbr < (*la)->next->nbr)
				double_swap(la, lb);
			else 
				swap(lb, 'b');
			i++;
		}
		double_rev_rotate(la, lb);
		i++;
	}
	return (i);
}