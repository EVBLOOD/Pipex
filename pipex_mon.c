/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:29:38 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/07 12:48:24 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_commands	*ft_optigetcmd(t_commands **head, char *str)
{
	perror(str);
	ft_lstclear(head);
	return (NULL);
}

t_commands	*get_all_cmds(int nb, char **args, char **path)
{
	int			i;
	t_commands	*head;
	t_commands	*tmp;

	if (!path)
		exit (1);
	i = 0;
	head = NULL;
	while ((nb - 3) - i)
	{
		tmp = ft_check_for_cmd(args[2 + i], path);
		if (!tmp)
			return (ft_optigetcmd(&head, args[2 + i]));
		if (!i)
			tmp->the_first = 1;
		else
			tmp->the_first = 0;
		ft_lstadd_back(&head, tmp);
		i++;
	}
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
	return (head);
}

int	ft_first_in_mobn(t_all_data *stock)
{
	if (dup2(stock->fd_file1, 0) < 0)
		exit (1);
	if (close(stock->pipe_fds[0]))
		exit (1);
	if (dup2(stock->pipe_fds[1], 1) < 0)
		exit (1);
	return (0);
}

int	ft_second_in_mobn(t_all_data *stock)
{
	if (dup2(stock->pipe_fds[1], 1) < 0)
		exit (1);
	if (close(stock->pipe_fds[0]))
		exit (1);
	return (0);
}

int	ft_nonext(char *filename, t_all_data *stock)
{
	stock->fd_file2 = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (stock->fd_file2 < 0)
	{
		perror("FILE");
		exit (1);
	}
	if (dup2(stock->fd_file2, 1) < 0)
		exit (1);
	if (close(stock->pipe_fds[0]))
		exit (1);
	return (0);
}
