/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus2_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:24:54 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/07 13:44:49 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_voidoptim(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		free(path[i]);
		path[i] = NULL;
	}
	free(path);
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
			perror(args[3 + i]);
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
	ft_voidoptim(path);
	return (head);
}

int	ft_first_time_in(t_all_data	*stock)
{
	(*stock).fd_file1 = open(".her_doc", O_RDONLY);
	if ((*stock).fd_file1 < 0)
		ft_exitprog();
	ft_optifirtime(stock);
	return (0);
}

int	ft_second_time_in(t_all_data *stock, char *namefile)
{
	(*stock).fd_file2 = open(namefile, O_CREAT | O_WRONLY | O_APPEND, 00644);
	if ((*stock).fd_file2 < 0)
	{
		perror("FILE");
		exit (1);
	}
	dup2((*stock).fd_file2, 1);
	close((*stock).pipe_fds[0]);
	return (0);
}

void	parent_process(t_all_data *stock)
{
	dup2((*stock).pipe_fds[0], 0);
	close((*stock).pipe_fds[1]);
}
