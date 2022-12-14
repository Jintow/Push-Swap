/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_preparation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:17:22 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 11:36:24 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	analyzing_configuration(t_listi **lst, t_tab *tab)
{
	make_tab_piv(tab);
	add_infolst(lst, tab);
	split_categ(lst, tab->size_pivot);
}
