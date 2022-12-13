/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:41:03 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 19:47:43 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_print_exit(t_listi **la, t_listi **lb, char **cmd, int out);

void	execute_command(char *buffer, t_listi **la, t_listi **lb)
{
	t_listi	*temp;
	char	**cmd;
	int		i;

	cmd = ft_split(buffer, '\n');
	i = 0;
	while (cmd[i])
		if (!do_instruction(cmd[i++], la, lb))
			free_print_exit(la, lb, cmd, 0);
	temp = *la;
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			break ;
		temp = temp->next;
	}
	if (temp->next == NULL && !(*lb))
		free_print_exit(la, lb, cmd, 1);
	else
		free_print_exit(la, lb, cmd, -1);
}

void	free_print_exit(t_listi **la, t_listi **lb, char **cmd, int out)
{
	free_tab(cmd);
	ft_lstclear_loc(la);
	ft_lstclear_loc(lb);
	if (out == 0)
		write(2, "Error\n", 6);
	else if (out == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
