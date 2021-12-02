/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:34:01 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/02 20:42:51 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_commands
{
	char	**cmd;
	char	*pathcmd;
	struct s_commands	*next;
}	t_commands;

typedef struct s_all_data
{
	int	fd_file1;
	int	fd_file2;
	int	fork_respo;
	int	whileforks_respo;
	int	never_goin;
	int	pipe_respo;
	int	pipe_fds[2];
}	t_all_data;
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoinbeta(char const *s1, char const *s2);
void	ft_lstadd_front(t_commands **lst, t_commands *new);
t_commands	*ft_lstlast(t_commands *lst);
void	ft_lstadd_back(t_commands **lst, t_commands *new);
void	ft_lstadd_front(t_commands **lst, t_commands *new);
t_commands	*ft_lstlast(t_commands *lst);
void	ft_lstadd_back(t_commands **lst, t_commands *new);
void	ft_freelst(void ***s1, void **s2);
void	ft_lstclear(t_commands **tofree);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
#endif