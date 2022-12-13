/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:32:41 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 09:54:31 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_valid_format(char *str, char *comparing_base)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_inside(str[i], comparing_base))
			return (0);
		i++;
	}
	return (1);
}
