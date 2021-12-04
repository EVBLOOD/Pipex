/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:34:01 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/04 17:18:25 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
//getnextline
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd, char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(void **x);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_onlyline(char *b, int *c);
char	*ft_the_rest(char *keep, int endofnl);
int		ft_readline(int fd, char *buf, char **keep);
//pipex
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_commands
{
	char	**cmd;
	char	*pathcmd;
	int		the_first;
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
	int	tmp_fd;
}	t_all_data;
char	**ft_split(char const *s, char c);
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
char	*ft_strjoinalfa(char const *s1);
#endif