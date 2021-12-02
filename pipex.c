/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:10:49 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/02 20:42:35 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_commands	*ft_check_for_cmd(char *cmdline, char **path)
{
	t_commands	*cmd;
	int				i;

	cmd = malloc(sizeof(t_commands));
	cmd->cmd = ft_split(cmdline,  ' ');
	i = -1;
	while (path[++i])
	{
		cmd->pathcmd = ft_strjoinbeta(path[i], cmd->cmd[0]);
		if (!cmd->pathcmd)
		{
			free (cmd->cmd);
			return (NULL);
		}
		if (!access(cmd->pathcmd, X_OK))
			break;
		free(cmd->pathcmd);
	}
	if (access(cmd->pathcmd, X_OK))
		return (NULL);
	cmd->next = NULL;
	return (cmd);
}

char	**ft_get_executable_foulders(char **en)
{
	int		i;
	char	**result;
	char	*adrs;

	i = -1;
	while(en[++i])
	{
		if(!ft_strncmp(en[i], "PATH=", 5))
			break;
	}
	if (ft_strncmp(en[i], "PATH=", 5))
		return (NULL);
	adrs = &en[i][5];
	result = ft_split(adrs, ':');
	return (result);
}

t_commands	*get_all_cmds(int nb, char **args, char **path)
{
	int	i;
	t_commands	*Head;
	t_commands	*tmp;

	if (!path)
		return (NULL);	
	i = 0;
	Head = NULL;
	while ((nb - 3) - i)
	{
		tmp = ft_check_for_cmd(args[2 + i], path);
		if (!tmp)
		{
			ft_lstclear(&Head);
			return (NULL);
		}
		ft_lstadd_back(&Head, tmp);
		i++;
	}
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
	return (Head);
}

// void	ft_todo(t_all_data stock, t_commands cmd, int countparams)
// {

// }

int main(int ac, char **av, char **env)
{
	int i;
	t_commands	*cmd;
	t_all_data	stock;

	if (access(av[1], R_OK) || ac < 5)
		return (0);
	cmd = get_all_cmds(ac, av, ft_get_executable_foulders(env));
	if (!cmd)
		return (0);
	stock.pipe_respo = pipe(stock.pipe_fds);
	if (stock.pipe_respo < 0)
		return (0);
	stock.fd_file1 = open(av[1], O_RDONLY);
	if (stock.fd_file1 < 1)
		exit (1);
	stock.never_goin = 1;
	while (cmd)
	{
		stock.fork_respo = fork();
		if (stock.fork_respo < 0)
			return (0);
		if (stock.fork_respo != 0 && stock.never_goin)
		{
			dup2(stock.fd_file1, 0);
			dup2(stock.pipe_fds[1], 1);
			close(stock.pipe_fds[0]);
			execve(cmd->pathcmd, cmd->cmd, NULL);
		}
		else
		{
			cmd = cmd->next;
			if (!cmd->next)
			{
				waitpid(stock.fork_respo, NULL, 0);
				stock.fd_file2 = open(av[ac - 1], O_WRONLY | O_CREAT, 0777);
				dup2(stock.fd_file2, 1);
				close(stock.pipe_fds[1]);
				execve(cmd->pathcmd, cmd->cmd, NULL);
				exit (1);
			}
			else
			{
				waitpid(stock.fork_respo, NULL, 0);
				dup2(stock.pipe_fds[0], 0);
				dup2(stock.pipe_fds[1], 1);
				close(stock.pipe_fds[1]);
				stock.whileforks_respo = fork();
				if (stock.whileforks_respo > 0)
				{
					stock.never_goin = 0;
					execve(cmd->pathcmd, cmd->cmd, NULL);
				}
			}
		}
		printf("I was here!");
		cmd = cmd->next;
	}
	
	exit(0);
}