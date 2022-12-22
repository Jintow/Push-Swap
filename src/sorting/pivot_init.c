/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:11:43 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/22 14:34:26 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_rot_push(t_listi **la, t_listi **lb, int piv);
int	test_swap(t_listi **la, t_listi **lb, int piv);

/*
	First sort of the mid-lowest elements of the list-A (first sub-list);
	Among this sub-list, elements with low_piv = 1 go at then end of list-B
	with rotate or double rotate function.
	Elements with low_piv = 0 go at the top of List-B.
*/

void	pivot(t_listi **la, t_listi **lb, int piv)
{
	static unsigned int	i;
	int					lst_size;

	if (!(*la))
		return ;
	lst_size = (int)lst_size_loc(*la);
	while (lst_size-- > 0)
	{
		i += test_rot_push(la, lb, piv);
		i++;
		if (lst_size_loc(*la) == 2 || no_more_piv(*la, piv))
			break ;
	}
	if ((*lb) && (*lb)->low_piv == 1)
	{
		i++;
		rotate(lb, 'b');
	}
}

int	test_rot_push(t_listi **la, t_listi **lb, int piv)
{
	int	i;

	i = 0;
	if ((*la)->piv == piv)
	{
		if ((*lb) && (*lb)->low_piv == 1 && (*la)->low_piv == 0 && \
			(lst_size_loc(*lb) > 15))
			while ((*lb)->low_piv == 1 && (*lb)->piv == piv)
				rotate(lb, 'b');
		else if ((*lb) && (*lb)->low_piv == 1)
			rotate(lb, 'b');
		push(lb, la, 'b');
	}
	else
	{
		if ((*lb) && (*lb)->low_piv == 1 && (*lb)->piv == piv)
			double_rotate(la, lb);
		else
			rotate(la, 'a');
	}
	return (i);
}
