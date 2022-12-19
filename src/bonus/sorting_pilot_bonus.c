/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_pilot_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:21:20 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/19 14:08:10 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sort_two_or_three_bonus(t_listi **la, t_listi **lb);

void	sorting_pilot_bonus(t_listi **la, t_tab *tab)
{
	t_listi		*lb;
	char		buffer[1000000];
	int			size;

	lb = NULL;
	free(tab->tab);
	size = 0;
	while (read(0, &buffer[size], 1))
		size++;
	if (buffer[ft_strlen(buffer) - 1] != '\n' && ft_strlen(buffer) > 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	execute_command(buffer, la, &lb);
}
