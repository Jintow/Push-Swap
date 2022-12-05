/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:23:38 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/10 13:24:22 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str_conc;

	if (!s1 && !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen((char *)s1);
	if (s2)
		len2 = ft_strlen((char *)s2);
	str_conc = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str_conc)
		return (NULL);
	str_conc[len1 + len2] = 0;
	i = -1;
	while (++i < len1)
		str_conc[i] = s1[i];
	i = -1;
	while (++i < len2)
		str_conc[len1 + i] = s2[i];
	return (str_conc);
}
