/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_input_final.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:59:48 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/14 13:54:43 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_valid_one_arg(char *str);

void	final_checking1(char **tab_nb, t_tab *tab)
{
	int		checking;

	if (size_tab((void **)(tab_nb)) == 1 && \
		is_valid_one_arg(tab_nb[0]) && (tab_nb[0][0]))
	{
		free_tab(tab_nb);
		exit(0);
	}
	checking = central_checking(tab_nb, tab);
	if (checking <= 0)
	{
		if (checking == -1)
		{
			if (tab->tab)
				free(tab->tab);
			free_tab(tab_nb);
			exit (0);
		}
		else
		{
			free_tab(tab_nb);
			write(2, "Error\n", 6);
			exit (0);
		}
	}
}

void	final_checking2(char **tab_nb, t_tab *tab)
{
	int		checking;

	if (size_tab((void **)(tab_nb)) == 1 && \
		ft_is_valid_format(tab_nb[0], BASE_DEC) && tab_nb[0][0])
		exit(0);
	checking = central_checking(tab_nb, tab);
	if (checking <= 0)
	{
		if (checking == -1)
		{
			if (tab->tab)
				free(tab->tab);
			exit (0);
		}
		else
		{
			write(2, "Error\n", 6);
			exit (0);
		}
	}
}

int	is_valid_one_arg(char *str)
{
	int	sign;

	sign = 1;
	if ((*str) == '-')
	{
		sign = -1;
		str++;
	}
	if (ft_is_valid_format(str, BASE_DEC))
	{
		if (ft_strlen(str) < 10)
			return (1);
		if (ft_strlen(str) > 10)
			return (0);
		return (!overflowed_nb(str, sign));
	}
	return (0);
}
