/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:26:22 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 20:07:54 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "push_swap.h"

void	double_swap_bonus(t_listi **la, t_listi **lb);
void	double_rev_rotate_bonus(t_listi **la, t_listi **lb);
void	double_rotate_bonus(t_listi **la, t_listi **lb);
void	sorting_pilot_bonus(t_listi **la, t_tab *tab);
void	execute_command(char *buffer, t_listi **la, t_listi **lb);
void	gate_away_bonus(t_listi **la, t_listi **lb, char *buffer);
void	sorting_lb_bonus(t_listi **la, t_listi **lb, int i_piv, int low_piv);
int		do_instruction(char *cmd, t_listi **la, t_listi **lb);

#endif