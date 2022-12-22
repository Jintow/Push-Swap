/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:50:33 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/22 12:58:56 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Function that put all input arguments in one string.
	Then it split it to create an array of string.
*/

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
