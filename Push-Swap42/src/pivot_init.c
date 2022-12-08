/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:11:43 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/08 16:15:05 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_rot_push(t_listi **la, t_listi **lb, int i_piv);
int	test_swap(t_listi **la, t_listi **lb, int i_piv);

void	pivot(t_listi **la, t_listi **lb, int i_piv)
{
	static unsigned int	i;
	int			j;
	int			k;
	int			lst_size;

	if (!(*la))
		return ;
	lst_size = (int)lst_size_loc(*la);
	j = 0;
	k = 0;
	while (lst_size-- > 0)
	{
		i += test_swap(la, lb, i_piv);
		i += test_rot_push(la, lb, i_piv);
		i++;
		//print_listi(*la, *lb);
		if (lst_size_loc(*la) == 2 || no_more_piv(*la, i_piv))
			break;
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
	int i;

	i = 0;
	if ((*lb) && (*lb)->next && (*lb)->nbr > (*lb)->next->nbr && (*lb)->low_piv == (*lb)->next->low_piv)
	{	
		if (test_swap_la(la))
			double_swap(la, lb);
		else 
			swap(lb, 'b');
	
		i++;
	}
	if (test_swap_la(la))
	{
		swap(la, 'a');
		i++;
	}
	return (i);
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

int	no_more_piv(t_listi	*lst, int piv)
{
	while (lst)
	{
		if (lst->piv == piv)
			return (0);
		lst = lst->next;
	}
	return (1);
}
