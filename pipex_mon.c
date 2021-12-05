/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:29:38 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/05 22:50:18 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_commands	*ft_optigetcmd(t_commands **head)
{
	ft_lstclear(head);
	return (NULL);
}

t_commands	*get_all_cmds(int nb, char **args, char **path)
{
	int			i;
	t_commands	*head;
	t_commands	*tmp;

	if (!path)
		return (NULL);
	i = 0;
	head = NULL;
	while ((nb - 3) - i)
	{
		tmp = ft_check_for_cmd(args[2 + i], path);
		if (!tmp)
			return (ft_optigetcmd(&head));
		if (!i)
			tmp->the_first = 1;
		else
			tmp->the_first = 0;
		ft_lstadd_back(&head, tmp);
		i++;
	}
	free(path);
	return (head);
}

int	ft_first_in_mobn(t_all_data *stock)
{
	if (dup2(stock->fd_file1, 0) < 0)
		return (1);
	if (close(stock->pipe_fds[0]))
		return (1);
	if (dup2(stock->pipe_fds[1], 1) < 0)
		return (1);
	return (0);
}

int	ft_second_in_mobn(t_all_data *stock)
{
	if (dup2(stock->pipe_fds[1], 1) < 0)
		return (1);
	if (close(stock->pipe_fds[0]))
		return (1);
	return (0);
}

int	ft_nonext(char *filename, t_all_data *stock)
{
	unlink(filename);
	stock->fd_file2 = open(filename, O_WRONLY | O_CREAT, 0777);
	if (stock->fd_file2 < 0)
		return (1);
	if (dup2(stock->fd_file2, 1) < 0)
		return (1);
	if (close(stock->pipe_fds[0]))
		return (1);
	return (0);
}
