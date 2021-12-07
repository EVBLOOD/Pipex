/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:10:49 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/07 14:30:53 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isparent(t_all_data *stock, t_commands **cmd)
{
	if (dup2(stock->pipe_fds[0], 0) < 0)
		exit(1);
	if (close(stock->pipe_fds[1]))
		exit(1);
	*cmd = (*cmd)->next;
	stock->count += 1;
	return (0);
}

int	ft_ischild(t_commands *cmd, t_all_data *stock, char *file)
{
	if (cmd->next)
	{
		if (cmd->the_first)
		{
			if (ft_first_in_mobn(stock))
				exit(1);
		}
		else
		{
			if (ft_second_in_mobn(stock))
				exit(1);
		}
	}
	else
	{
		if (ft_nonext(file, stock))
			exit(1);
	}
	return (0);
}

int	pipex(int ac, char **av, char **env)
{
	t_commands	*cmd;
	t_all_data	stock;
	t_commands	*tmp;

	stock.fd_file1 = open(av[1], O_RDONLY);
	ft_baliseexit(&stock);
	cmd = get_all_cmds(ac, av, ft_get_executable_foulders(env));
	ft_conditioncmd(cmd, &tmp);
	while (cmd)
	{
		ft_fodu(&stock);
		if (!stock.fork_respo)
		{
			ft_ischild(cmd, &stock, av[ac - 1]);
			execve(cmd->pathcmd, cmd->cmd, NULL);
			exit(1);
		}
		else
			ft_isparent(&stock, &cmd);
	}
	while ((--stock.count + 1))
		waitpid(stock.fork_respo, NULL, 0);
	ft_tofree(&tmp);
	return (0);
}

void	ft_tofree(t_commands **tmp)
{
	int			i;
	t_commands	*pr;

	while ((*tmp))
	{
		i = -1;
		while ((*tmp)->cmd[++i])
			free((*tmp)->cmd[i]);
		free((*tmp)->pathcmd);
		free((*tmp)->cmd);
		pr = (*tmp);
		(*tmp) = (*tmp)->next;
		free(pr);
	}
	unlink(".her_doc");
}
