/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:22:10 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/05 19:02:26 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_the_rest(char *keep, int endofnl)
{
	int		i;
	char	*p;

	i = 0;
	if (keep[endofnl] == '\0')
	{
		p = (char *) malloc(sizeof(char));
		p[0] = '\0';
		return (p);
	}
	p = (char *) malloc(ft_strlen(&keep[endofnl]) + 1);
	if (!p)
		return (NULL);
	while (keep[endofnl + i])
	{
		p[i] = keep[endofnl + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_readline(int fd, char *buf, char **keep)
{
	char	*tmp;
	int		con;

	con = 1;
	if (!*keep)
	{
		*keep = (char *)malloc(sizeof(char));
		*keep[0] = '\0';
	}
	while (*keep && !ft_strchr(*keep, '\n') && con == 1)
	{
		con = read(fd, buf, 1);
		if (con > 0)
		{
			buf[con] = '\0';
			tmp = ft_strjoin(*keep, buf);
			ft_free((void *) keep);
			*keep = tmp;
		}
		else
			return (0);
	}
	return (con);
}

char	*get_next_line(int fd, char *str)
{
	static char	*keep;
	char		*buf;
	int			endofnl;
	int			i;
	char		*tmp;

	buf = (char *)malloc((1 + 1) * sizeof(char));
	i = ft_readline(fd, buf, &keep);
	if (keep[0] == '\0')
	{
		ft_free((void *) &keep);
		ft_free((void *) &buf);
		return (NULL);
	}
	ft_free((void *) &buf);
	buf = ft_onlyline(keep, &endofnl);
	if (buf && (ft_strchr(buf, '\n') || ft_strlen(buf) > 0))
	{
		tmp = ft_the_rest(keep, endofnl);
		ft_free((void *)&keep);
		keep = tmp;
	}
	if (ft_strcmp(buf, str) == 0)
		buf = NULL;
	return (buf);
}
