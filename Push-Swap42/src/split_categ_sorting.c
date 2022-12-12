/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_categ_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:16:55 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/12 20:24:52 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_categ_down_mod3(t_listi *temp, int piv, int low_piv, int max);
void	if_categ_up_mod3(t_listi *temp, int piv, int low_piv, int max);
void	if_categ_mod3(t_listi *temp, int piv, int low_piv, int max);

void	split_categ_sorting(t_listi **lst, int piv, int low_piv, int max)
{
	t_listi	*temp;

	temp = *lst;
	while (temp && temp->low_piv == low_piv && temp->piv == piv)
	{
		if (max % 3 == 0)
			if_categ_mod3(temp, piv, low_piv, max);
		else if ((max - 1) % 3 == 0)
			if_categ_up_mod3(temp, piv, low_piv, max);
		else
			if_categ_down_mod3(temp, piv, low_piv, max);
		temp = temp->next;
	}
}

void	if_categ_mod3(t_listi *temp, int piv, int low_piv, int max)
{
	if (temp->pos < max / 3)
		temp->low_piv -= 2;
	else if (temp->pos < (2 * max / 3))
	{
		temp->low_piv -= 1;
		temp->pos -= max / 3;
	}
	else
		temp->pos -= 2 * max / 3;
}

void	if_categ_up_mod3(t_listi *temp, int piv, int low_piv, int max)
{
	if (temp->pos < max / 3)
		temp->low_piv -= 2;
	else if (temp->pos < 2 * max / 3)
	{
		temp->low_piv -= 1;
		temp->pos -= max / 3;
	}
	else
		temp->pos -= 2 * max / 3;
}

void	if_categ_down_mod3(t_listi *temp, int piv, int low_piv, int max)
{
	if (temp->pos < max / 3)
		temp->low_piv -= 2;
	else if (temp->pos < 2 * max / 3)
	{
		temp->low_piv -= 1;
		temp->pos -= max / 3;
	}
	else
		temp->pos -= (2 * (max / 3) + 1);
}
