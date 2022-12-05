/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:50:56 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/10 12:57:08 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare_str(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] == to_find[i] && i < len)
	{
		if (to_find[i + 1] == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	max;

	if (ft_strlen((char *)to_find) == 0)
		return ((char *)str);
	if (!str && len == 0)
		return (NULL);
	max = ft_strlen(to_find);
	i = 0;
	while (str[i] && i < len && max + i <= len)
	{
		if (compare_str(&str[i], to_find, len))
			return (&((char *)str)[i]);
		i++;
	}
	return (NULL);
}
