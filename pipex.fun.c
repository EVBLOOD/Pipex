/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:30:59 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/05 22:51:53 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_opticheckcmd(t_commands **cmd, char *cmdline)
{
	*cmd = malloc(sizeof(t_commands));
	if (!(*cmd))
		return (1);
	(*cmd)->cmd = ft_split(cmdline, ' ');
	if (!(*cmd)->cmd)
		return (1);
	return (0);
}

t_commands	*ft_check_for_cmd(char *cmdline, char **path)
{
	t_commands	*cmd;
	int			i;

	if (ft_opticheckcmd(&cmd, cmdline))
		return (NULL);
	i = -1;
	while (path[++i])
	{
		cmd->pathcmd = ft_strjoinbeta(path[i], cmd->cmd[0]);
		if (!cmd->pathcmd)
			return (NULL);
		if (!access(cmd->pathcmd, X_OK))
			break ;
		free(cmd->pathcmd);
	}
	cmd->next = NULL;
	if (!path[i])
		return (NULL);
	return (cmd);
}

char	**ft_get_executable_foulders(char **en)
{
	int		i;
	char	**result;
	char	*adrs;

	i = -1;
	while (en[++i])
	{
		if (!ft_strncmp(en[i], "PATH=", 5))
			break ;
	}
	if (ft_strncmp(en[i], "PATH=", 5))
		return (NULL);
	adrs = &en[i][5];
	result = ft_split(adrs, ':');
	return (result);
}
