/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:54:40 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/15 01:04:48 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free_str(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
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
		return (ft_free_str(s1));
	str_conc[len1 + len2] = 0;
	i = -1;
	while (++i < len1)
		str_conc[i] = s1[i];
	free(s1);
	i = -1;
	while (++i < len2)
		str_conc[len1 + i] = s2[i];
	return (str_conc);
}
