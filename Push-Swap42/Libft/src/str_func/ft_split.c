/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:53:23 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/05 14:33:21 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		nb_word;
	int		i;
	int		j;
	char	**tab_word;

	tab_word = malloc(sizeof(char *) * (count_word((char *)s, c) + 1));
	if (!tab_word || !s)
		return (free_tab(tab_word));
	nb_word = 0 ;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			tab_word[nb_word] = ft_strndup(&s[i], (size_t)j);
			if (!(tab_word[nb_word++]))
				return (free_tab(tab_word));
			i += j - 1;
		}
	}
	tab_word[nb_word] = 0;
	return (tab_word);
}
