/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:10:49 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/05 22:53:32 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isparent(t_all_data *stock, t_commands **cmd)
{
	waitpid(0, NULL, 0);
	if (dup2(stock->pipe_fds[0], 0) < 0)
		return (1);
	if (close(stock->pipe_fds[1]))
		return (1);
	*cmd = (*cmd)->next;
	return (0);
}

int	ft_ischild(t_commands *cmd, t_all_data *stock, char *file)
{
	if (cmd->next)
	{
		if (cmd->the_first)
		{
			if (ft_first_in_mobn(stock))
				return (1);
		}
		else
		{
			if (ft_second_in_mobn(stock))
				return (1);
		}
	}
	else
	{
		if (ft_nonext(file, stock))
			return (1);
	}
	return (0);
}

int	pipex(int ac, char **av, char **env)
{
	t_commands	*cmd;
	t_all_data	stock;

	stock.fd_file1 = open(av[1], O_RDONLY);
	if (stock.fd_file1 < 1)
		exit (1);
	cmd = get_all_cmds(ac, av, ft_get_executable_foulders(env));
	if (!cmd)
		return (0);
	while (cmd)
	{
		if (ft_fodu(&stock) < 0)
			return (0);
		if (!stock.fork_respo)
		{
			if (ft_ischild(cmd, &stock, av[ac - 1]))
				return (1);
			execve(cmd->pathcmd, cmd->cmd, NULL);
		}
		else
			if (ft_isparent(&stock, &cmd))
				return (1);
	}
	return (0);
}
