/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/19 13:57:40 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_tab	tab;
	t_listi	*la;
	char	**tab_nb;
	char	*value;

	if (argc == 1)
		return (0);
	la = NULL;
	value = ft_strjoin("", "");
	i = 0;
	while (argv[++i])
	{
		value = ft_strjoin_free(value, argv[i]);
		value = ft_strjoin_free(value, " ");
	}
	tab_nb = ft_split(value, ' ');
	free(value);
	tab.bonus = 0;
	final_checking(tab_nb, &tab);
	i = 0;
	while (tab_nb[i])
		ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(tab_nb[i++])));
	free_tab(tab_nb);
	sorting_pilot(&la, &tab);
}
