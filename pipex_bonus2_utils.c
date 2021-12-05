/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus2_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:24:54 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/05 23:40:10 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_voidoptim(char ***path)
{
	int	i;

	i = -1;
	while ((*path)[++i])
		free((*path)[i]);
	free(*path);
}

t_commands	*get_all_cmds_second(int nb, char **args, char **path)
{
	int			i;
	t_commands	*head;
	t_commands	*tmp;

	i = 0;
	head = NULL;
	while ((nb - 4) - i)
	{
		tmp = ft_check_for_cmd(args[3 + i], path);
		if (!tmp)
		{
			ft_lstclear(&head);
			return (NULL);
		}
		if (!i)
			tmp->the_first = 1;
		else
			tmp->the_first = 0;
		ft_lstadd_back(&head, tmp);
		i++;
	}
	ft_voidoptim(&path);
	return (head);
}

int	ft_first_time_in(t_all_data	*stock, char *her_doc)
{
	char	*rm;
	char	*line;

	rm = ft_strjoinalfa(her_doc);
	if (!rm)
		return (1);
	(*stock).fd_file1 = open(".her_doc", O_CREAT | O_WRONLY, 0777);
	if ((*stock).fd_file1 < 0)
		return (1);
	write(1, "pipe heredoc> ", 14);
	line = get_next_line(1, rm);
	while (line)
	{
		write(1, "pipe heredoc> ", 14);
		write((*stock).fd_file1, line, ft_strlen(line));
		free(line);
		line = get_next_line(1, rm);
	}
	close((*stock).fd_file1);
	(*stock).fd_file1 = open(".her_doc", O_RDONLY);
	close((*stock).pipe_fds[0]);
	dup2((*stock).fd_file1, 0);
	dup2((*stock).pipe_fds[1], 1);
	return (0);
}

int	ft_second_time_in(t_all_data *stock, char *namefile)
{
	(*stock).fd_file2 = open(namefile, O_WRONLY | O_APPEND | O_CREAT, 0777);
	if ((*stock).fd_file2 < 0)
		return (1);
	dup2((*stock).fd_file2, 1);
	close((*stock).pipe_fds[0]);
	return (0);
}

void	parent_process(t_all_data *stock)
{
	waitpid(0, NULL, 0);
	dup2((*stock).pipe_fds[0], 0);
	close((*stock).pipe_fds[1]);
}
