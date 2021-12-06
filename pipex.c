/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:10:49 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/06 16:28:46 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isparent(t_all_data *stock, t_commands **cmd)
{
	waitpid(0, NULL, 0);
	if (dup2(stock->pipe_fds[0], 0) < 0)
		exit (1);
	if (close(stock->pipe_fds[1]))
		exit (1);
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
				exit (1);
		}
		else
		{
			if (ft_second_in_mobn(stock))
				exit (1);
		}
	}
	else
	{
		if (ft_nonext(file, stock))
			exit (1);
	}
	return (0);
}

int	pipex(int ac, char **av, char **env)
{
	t_commands	*cmd;
	t_all_data	stock;

	stock.fd_file1 = open(av[1], O_RDONLY);
	if (stock.fd_file1 < 1)
	{
		perror("FILE:");
		exit (1);
	}
	cmd = get_all_cmds(ac, av, ft_get_executable_foulders(env));
	if (!cmd)
		exit (1);
	while (cmd)
	{
		ft_fodu(&stock);
		if (!stock.fork_respo)
		{
			ft_ischild(cmd, &stock, av[ac - 1]);
			execve(cmd->pathcmd, cmd->cmd, NULL);
		}
		else
			ft_isparent(&stock, &cmd);
	}
	return (0);
}

void	ft_exitprog(void)
{
	perror("FILE");
	exit (1);
}

void	ft_optifirtime(t_all_data *stock)
{
	close((*stock).pipe_fds[0]);
	dup2((*stock).fd_file1, 0);
	dup2((*stock).pipe_fds[1], 1);
}
