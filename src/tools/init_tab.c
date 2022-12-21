/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:50:33 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/21 13:51:28 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
