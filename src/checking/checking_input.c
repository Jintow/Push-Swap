/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:22:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/21 13:27:23 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	characters_checking(char **tab);
int	overflowing_checking(char **tab);
int	no_duplicated_no_sorted_checking(t_tab *tab, int size);

int	central_checking(char **tab_nb, t_tab *tab)
{
	if (!characters_checking(tab_nb))
		return (0);
	if (!overflowing_checking(tab_nb))
		return (0);
	tab->size = size_tab((void **)tab_nb);
	tab->tab = make_tab(tab_nb, tab->size);
	tab->str_tab = tab_nb;
	return (no_duplicated_no_sorted_checking(tab, tab->size));
}

int	characters_checking(char **tab)
{
	int		i;
	char	*nb;

	if (size_tab((void **)tab) == 0 && !(ft_strlen(tab[0])))
		return (0);
	i = 0;
	while (tab[i])
	{
		nb = tab[i];
		if (*nb == '-')
		{
			nb++;
			if (!(*nb))
				return (0);
		}
		if (!ft_is_valid_format(nb, BASE_DEC))
			return (0);
		i++;
	}
	return (1);
}

int	overflowed_nb(char *nb, int sign)
{
	if (sign < 0)
	{
		if (ft_strcmp(CHAR_INT_MIN, nb) < 0)
			return (1);
	}
	else
	{
		if (ft_strcmp(CHAR_INT_MAX, nb) < 0)
			return (1);
	}
	return (0);
}

int	overflowing_checking(char **tab)
{
	int		i;
	int		sign;
	int		len;
	char	*nb;

	i = 0;
	while (tab[i])
	{
		sign = 1;
		nb = tab[i];
		if (*nb == '-')
		{
			sign = -1;
			nb++;
		}
		while (*nb == '0')
			nb++;
		len = ft_strlen(nb);
		if (len > 10)
			return (0);
		else if (len == 10 && overflowed_nb(nb, sign))
			return (0);
		i++;
	}
	return (1);
}

int	no_duplicated_no_sorted_checking(t_tab *tab, int size)
{
	int		i;
	int		*tab_nb;

	tab_nb = tab->tab;
	i = 0;
	while (i < size - 1 && tab->bonus == 0)
	{
		if (tab_nb[i] >= tab_nb[i + 1])
			break ;
		i++;
	}
	if (i == size - 1)
		return (-1);
	sort_merge(tab);
	tab_nb = tab->tab;
	i = 0;
	while (i < size - 1)
	{
		if (tab_nb[i] == tab_nb[i + 1])
			return (-2);
		i++;
	}
	return (1);
}