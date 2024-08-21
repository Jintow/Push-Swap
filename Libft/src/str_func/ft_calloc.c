/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:09:07 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/11 09:26:24 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*p;

	if (nb != 0 && 2147483647 / nb < size)
		return (NULL);
	p = malloc(nb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nb * size);
	return (p);
}
