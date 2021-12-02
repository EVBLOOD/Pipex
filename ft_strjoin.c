/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:45:19 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/30 18:21:08 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoinbeta(char const *s1, char const *s2)
{
	int		i;
	int		k;
	int		count;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	k = ft_strlen(s2);
	count = i + k + 2;
	p = (char *) malloc(count * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	k = i;
	while (s1[k])
		p[i++] = s1[k++];
	p[i++] = '/';
	k = 0;
	while (s2[k])
		p[i++] = s2[k++];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoinalfa(char const *s1, char const *s2)
{
	int		i;
	int		k;
	int		count;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	k = ft_strlen(s2);
	count = i + k + 4;
	p = (char *) malloc(count * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	k = i;
	p[i++] = '<';
	p[i++] = ' ';
	while (s1[k])
		p[i++] = s1[k++];
	p[i++] = ' ';
	k = 0;
	while (s2[k])
		p[i++] = s2[k++];
	p[i] = '\0';
	return (p);
}
