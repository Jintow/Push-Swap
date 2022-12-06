/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:30:42 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/05 14:31:29 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *s, char c)
{
	int	nb_word;
	int	i;

	if (!s)
		return (0);
	if (!c)
		return (1);
	nb_word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
			nb_word ++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb_word);
}
