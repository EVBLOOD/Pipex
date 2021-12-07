/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:11:09 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/07 14:40:59 by sakllam          ###   ########.fr       */
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

int	ft_ifchiled(t_all_data	*stock, t_commands *cmd, char *f)
{
	if (cmd->next)
	{
		if (ft_first_time_in(stock))
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
	t_commands	*tmp;

	cmd = get_all_cmds_second(ac, av, ft_get_executable_foulders(env));
	ft_deletelins(cmd, &tmp, &stock, av[2]);
	while (cmd)
	{
		if (ft_fodu(&stock) < 0)
			exit (1);
		if (stock.fork_respo == 0)
		{
			if (ft_ifchiled(&stock, cmd, av[ac - 1]))
				exit (1);
			if (execve(cmd->pathcmd, cmd->cmd, NULL) < 0)
				exit (1);
		}
		parent_process(&stock);
		cmd = cmd->next;
	}
	while (--stock.count)
		waitpid(stock.fork_respo, NULL, 0);
	ft_tofree(&tmp);
	return (0);
}

void	ft_deletelins(t_commands *cmd, t_commands **tmp,
						t_all_data *stock, char *h)
{
	if (!cmd)
		exit (1);
	*tmp = cmd;
	ft_heredoc(stock, h);
}
