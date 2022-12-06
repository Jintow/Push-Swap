/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:36:06 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/05 14:22:19 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	size_t	len;
	char	*src_copy;

	len = 0;
	while (src[len] && len < n)
		len++;
	src_copy = malloc(sizeof(char) * (len + 1));
	if (!src_copy)
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{	
		src_copy[i] = src[i];
		i++;
	}
	src_copy[i] = 0;
	return (src_copy);
}
