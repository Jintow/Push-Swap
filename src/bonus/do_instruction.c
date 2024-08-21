/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:38:55 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/14 09:57:38 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_instruction3(char *cmd, t_listi **la, t_listi **lb);
int	do_instruction2(char *cmd, t_listi **la, t_listi **lb);

int	do_instruction(char *cmd, t_listi **la, t_listi **lb)
{
	if (!ft_strcmp(cmd, "sa"))
	{
		swap(la, '0');
		return (1);
	}
	else if (!ft_strcmp(cmd, "sb"))
	{
		swap(lb, '0');
		return (1);
	}
	else if (!ft_strcmp(cmd, "ss"))
	{
		double_swap_bonus(lb, la);
		return (1);
	}
	else if (!ft_strcmp(cmd, "ra"))
	{
		rotate(la, '0');
		return (1);
	}
	else
		return (do_instruction2(cmd, la, lb));
}

int	do_instruction2(char *cmd, t_listi **la, t_listi **lb)
{
	if (!ft_strcmp(cmd, "rb"))
	{
		rotate(lb, '0');
		return (1);
	}
	else if (!ft_strcmp(cmd, "rr"))
	{
		double_rotate_bonus(lb, la);
		return (1);
	}
	else if (!ft_strcmp(cmd, "rra"))
	{
		rev_rotate(la, '0');
		return (1);
	}
	else if (!ft_strcmp(cmd, "rrb"))
	{
		rev_rotate(lb, '0');
		return (1);
	}
	else
		return (do_instruction3(cmd, la, lb));
}

int	do_instruction3(char *cmd, t_listi **la, t_listi **lb)
{
	if (!ft_strcmp(cmd, "rrr"))
	{
		double_rev_rotate_bonus(lb, la);
		return (1);
	}
	else if (!ft_strcmp(cmd, "pa"))
	{
		push(la, lb, '0');
		return (1);
	}
	else if (!ft_strcmp(cmd, "pb"))
	{
		push(lb, la, '0');
		return (1);
	}
	else
		return (0);
}
