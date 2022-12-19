/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/19 19:29:17 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	**init_tab(char **argv);
void	create_list(t_listi	**la, char **tab_nb);

int	main(int argc, char **argv)
{
	t_tab	tab;
	t_listi	*la;
	char	**tab_nb;

	if (argc == 1)
		return (0);
	la = NULL;
	tab.bonus = 0;
	tab_nb = init_tab(&argv[1]);
	final_checking(tab_nb, &tab);
	create_list(&la, tab_nb);
	free_tab(tab_nb);
	sorting_pilot(&la, &tab);
}

char	**init_tab(char **argv)
{
	char	*value;
	char	**tab_nb;
	int		i;

	value = ft_calloc(1, sizeof(char));
	if (!value)
		exit(EXIT_FAILURE);
	i = -1;
	while (argv[++i])
	{
		value = ft_strjoin_free(value, argv[i]);
		if (!value)
			exit(EXIT_FAILURE);
		value = ft_strjoin_free(value, " ");
		if (!value)
			exit(EXIT_FAILURE);
	}
	tab_nb = ft_split(value, ' ');
	free(value);
	if (!tab_nb)
		exit(EXIT_FAILURE);
	return (tab_nb);
}

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
