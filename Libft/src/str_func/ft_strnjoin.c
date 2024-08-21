/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:26:27 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/05 14:25:00 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str_conc;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = 0;
	while (s2[len2] && len2 < size)
		len2++;
	str_conc = malloc(sizeof(char) * (len1 + len2 + 1));
	str_conc[len1 + len2] = 0;
	i = -1;
	while (++i < len1)
		str_conc[i] = s1[i];
	i = -1;
	while (++i < len2)
		str_conc[len1 + i] = s2[i];
	return (str_conc);
}
