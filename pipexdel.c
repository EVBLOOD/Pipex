/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:11:09 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/06 16:27:50 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_fodu(t_all_data *stock)
{
	stock->pipe_respo = pipe(stock->pipe_fds);
	if (stock->pipe_respo < 0)
	{
		write(2, "piping error", 12);
		exit (1);
	}
	stock->fork_respo = fork();
	if (stock->fork_respo < 0)
	{
		write(2, "fork error", 10);
		exit (1);
	}
	return (0);
}

int	ft_ifchiled(t_all_data	*stock, t_commands *cmd, char *h, char *f)
{
	if (cmd->next)
	{
		if (ft_first_time_in(stock, h))
			exit (1);
	}
	else
	{
		if (ft_second_time_in(stock, f))
			exit (1);
	}
	return (0);
}

int	pipexdel2(int ac, char **av, char **env)
{
	t_commands	*cmd;
	t_all_data	stock;

	cmd = get_all_cmds_second(ac, av, ft_get_executable_foulders(env));
	if (!cmd)
		return (0);
	while (cmd)
	{
		if (ft_fodu(&stock) < 0)
			exit (1);
		if (stock.fork_respo == 0)
		{
			if (ft_ifchiled(&stock, cmd, av[2], av[ac - 1]))
				exit (1);
			if (execve(cmd->pathcmd, cmd->cmd, NULL) < 0)
				exit (1);
		}
		parent_process(&stock);
		cmd = cmd->next;
	}
	unlink(".her_doc");
	return (0);
}
