/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:11:43 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/15 02:14:37 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_rot_push(t_listi **la, t_listi **lb, int i_piv);
int	test_swap(t_listi **la, t_listi **lb, int i_piv);

void	pivot(t_listi **la, t_listi **lb, int i_piv)
{
	static unsigned int	i;
	int					lst_size;

	if (!(*la))
		return ;
	lst_size = (int)lst_size_loc(*la);
	while (lst_size-- > 0)
	{
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
}

int	test_rot_push(t_listi **la, t_listi **lb, int i_piv)
{
	int	i;

	i = 0;
	if ((*la)->piv == i_piv)
	{
		if ((*lb) && (*lb)->low_piv == 1 && (*la)->low_piv == 0 && \
			(lst_size_loc(*lb) > 15))
			while ((*lb)->low_piv == 1 && (*lb)->piv == i_piv)
				rotate(lb, 'b');
		else if ((*lb) && (*lb)->low_piv == 1)
			rotate(lb, 'b');
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
