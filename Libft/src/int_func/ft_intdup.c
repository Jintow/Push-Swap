/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:40:29 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/05 17:28:32 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intdup(const int *src, size_t size)
{
	size_t		i;
	int			*src_copy;

	i = 0;
	src_copy = malloc(sizeof(int) * (size));
	if (!src_copy)
		return (NULL);
	i = 0;
	while (i < size)
	{	
		src_copy[i] = src[i];
		i++;
	}
	return (src_copy);
}
