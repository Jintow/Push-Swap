/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:22:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 12:02:07 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	characters_checking(char **tab);
int	overflowing_checking(char **tab);
int	no_duplicated_no_sorted_checking(t_tab *tab, int size);

int	central_checking(char **tab_nb, t_tab *tab)
{
	int	dup_sort_check;

	if (!characters_checking(tab_nb))
		return (0);
	if (!overflowing_checking(tab_nb))
		return (0);
	tab->size = size_tab((void **)tab_nb);
	if (tab->size == 1)
		return (-1);
	tab->tab = make_tab(tab_nb, tab->size);
	dup_sort_check = no_duplicated_no_sorted_checking(tab, tab->size);
	if (dup_sort_check <= 0)
		return (dup_sort_check);
	return (1);
}

int	characters_checking(char **tab)
{
	int		i;
	char	*nb;

	i = 0;
	while (tab[i])
	{
		nb = tab[i];
		if (*nb == '-')
			nb++;
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
	size_t	i;
	int		*tab_nb;

	tab_nb = tab->tab;
	i = 0;
	while (i < size - 1)
	{
		if (tab_nb[i] > tab_nb[i + 1])
			break ;
		if (tab_nb[i] == tab_nb[i + 1])
			return (0);
		i++;
		if (i == size -1)
			return (-1);
	}
	sort_merge(tab);
	tab_nb = tab->tab;
	i = 0;
	while (i < size - 1)
	{
		if (tab_nb[i] == tab_nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}
