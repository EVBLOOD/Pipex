/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:34:01 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/05 22:53:57 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_commands
{
	char				**cmd;
	char				*pathcmd;
	int					the_first;
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

int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strjoinbeta(char const *s1, char const *s2);
char			*ft_strjoinalfa(char const *s1);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_free(void **x);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_onlyline(char *b, int *c);
char			*ft_the_rest(char *keep, int endofnl);
int				ft_readline(int fd, char *buf, char **keep);
char			*get_next_line(int fd, char *str);
void			ft_lstadd_front(t_commands **lst, t_commands *new);
void			ft_lstadd_back(t_commands **lst, t_commands *new);
void			ft_freelst(void ***s1, void **s2);
void			ft_lstclear(t_commands **tofree);
void			ft_voidoptim(char ***path);
t_commands		*get_all_cmds_second(int nb, char **args, char **path);
int				ft_first_time_in(t_all_data	*stock, char *her_doc);
int				ft_second_time_in(t_all_data *stock, char *namefile);
void			parent_process(t_all_data *stock);
t_commands		*ft_optigetcmd(t_commands **head);
t_commands		*get_all_cmds(int nb, char **args, char **path);
int				ft_first_in_mobn(t_all_data *stock);
int				ft_second_in_mobn(t_all_data *stock);
int				ft_nonext(char *filename, t_all_data *stock);
int				ft_isparent(t_all_data *stock, t_commands **cmd);
int				ft_ischild(t_commands *cmd, t_all_data *stock, char *file);
int				pipex(int ac, char **av, char **env);
int				ft_opticheckcmd(t_commands **cmd, char *cmdline);
t_commands		*ft_check_for_cmd(char *cmdline, char **path);
char			**ft_get_executable_foulders(char **en);
int				ft_fodu(t_all_data *stock);
int				ft_ifchiled(t_all_data	*stock,
					t_commands *cmd, char *h, char *f);
int				pipexdel2(int ac, char **av, char **env);
static size_t	ft_count(char const *s, char c);
static char		**free_tab(char **tab);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
#endif
