/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultrafunctionfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:20:19 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/07 14:18:47 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exitprog(void)
{
	perror("FILE");
	exit(1);
}

void	ft_optifirtime(t_all_data *stock)
{
	close((*stock).pipe_fds[0]);
	dup2((*stock).fd_file1, 0);
	dup2((*stock).pipe_fds[1], 1);
}

void	ft_conditioncmd(t_commands *cmd, t_commands **tmp)
{
	if (!cmd)
		exit(1);
	*tmp = cmd;
}

void	ft_heredoc(t_all_data *stock, char *here)
{
	char	*rm;
	char	*line;

	rm = ft_strjoinalfa(here);
	stock->count = 3;
	stock->fd_file1 = open(".her_doc", O_CREAT | O_WRONLY, 00644);
	if (stock->fd_file1 < 0)
		ft_exitprog();
	write(1, "pipe heredoc> ", 14);
	line = get_next_line(1, rm);
	while (line)
	{
		write(1, "pipe heredoc> ", 14);
		write(stock->fd_file1, line, ft_strlen(line));
		free(line);
		line = get_next_line(1, rm);
	}
	free(rm);
	close(stock->fd_file1);
}

char	*ft_docenf(char	**buf)
{
	free(*buf);
	return (NULL);
}
