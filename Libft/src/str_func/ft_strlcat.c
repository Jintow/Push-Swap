/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:48:49 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/12 14:34:06 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	if ((!src || !dest) && size == 0)
		return (0);
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (len_dest < size - 1 && size > 0)
	{
		i = 0;
		while (i < size - len_dest - 1 && i < len_src)
		{
			dest[len_dest + i] = src[i];
			i++;
		}
		dest[len_dest + i] = 0;
	}
	if (len_dest > size)
		len_dest = size;
	return (len_dest + len_src);
}
