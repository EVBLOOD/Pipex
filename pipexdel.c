/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:11:09 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/04 20:35:25 by sakllam          ###   ########.fr       */
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
	if (!path[i])
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
	while ((nb - 4) - i)
	{
		tmp = ft_check_for_cmd(args[3 + i], path);
		if (!tmp)
		{
			ft_lstclear(&Head);
			return (NULL);
		}
		if (!i)
			tmp->the_first = 1;
		else
			tmp->the_first = 0;
		ft_lstadd_back(&Head, tmp);
		i++;
	}
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
	return (Head);
}

int main(int ac, char **av, char **env)
{
	int i;
	t_commands	*cmd;
	t_all_data	stock;

	if (ac != 6)
		return (0);
	cmd = get_all_cmds(ac, av, ft_get_executable_foulders(env));
	if (!cmd)
		return (0);
	while (cmd)
	{
		stock.pipe_respo = pipe(stock.pipe_fds);
		if (stock.pipe_respo < 0)
			return (0);
		stock.fork_respo = fork();
		if (stock.fork_respo < 0)
			return (0);
		if (stock.fork_respo == 0)
		{
			if (cmd->next)
			{
				stock.fd_file1 = open(".her_doc", O_CREAT | O_RDWR , 0777);
				char *rm = ft_strjoinalfa(av[2]);
				char *test;
				while((test = get_next_line(1, rm)))
					write(stock.fd_file1, test, ft_strlen(test));
				close(stock.pipe_fds[0]);
				dup2(stock.fd_file1, 0);
				dup2(stock.pipe_fds[1], 1);
			}
			else
			{
				if (access(av[ac - 1], F_OK))
				{
					stock.fd_file2 = open(av[ac - 1], O_WRONLY | O_APPEND, 0777);
				}
				else
					stock.fd_file2 = open(av[ac - 1], O_CREAT | O_WRONLY , 0777);
				dup2(stock.fd_file2, 1);
				close(stock.pipe_fds[0]);
			}
			execve(cmd->pathcmd, cmd->cmd, NULL);
		}
		else
		{
			waitpid(0, NULL, 0);
			dup2(stock.pipe_fds[0], 0);
			close(stock.pipe_fds[1]);
			cmd = cmd->next;
		}
	}
	unlink(".her_doc");
	return (0);
}