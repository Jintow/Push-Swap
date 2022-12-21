/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lista.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:53:14 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/21 13:53:32 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(t_listi	**la, char **tab_nb)
{
	int		i;
	t_listi	*new;

	i = 0;
	while (tab_nb[i])
	{
		new = ft_lstnew_loc(ft_atoi(tab_nb[i++]));
		if (!new)
		{
			ft_lstclear_loc(la);
			free_tab(tab_nb);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back_loc(la, new);
	}
}
