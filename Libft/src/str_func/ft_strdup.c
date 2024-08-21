/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:40:29 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/11 10:54:29 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*src_copy;

	i = 0;
	while (src[i])
		i++;
	len = i;
	src_copy = malloc(sizeof(char) * (len + 1));
	if (!src_copy)
		return (NULL);
	i = 0;
	while (src[i])
	{	
		src_copy[i] = src[i];
		i++;
	}
	src_copy[i] = 0;
	return (src_copy);
}
