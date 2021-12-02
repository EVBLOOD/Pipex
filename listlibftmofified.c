/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listlibftmofified.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:03:32 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/02 19:28:38 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_lstadd_front(t_commands **lst, t_commands *new)
{
	new->next = *lst;
	*lst = new;
}

t_commands	*ft_lstlast(t_commands *lst)
{
	t_commands	*temp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		temp = lst;
		lst = lst->next;
	}
	return (temp);
}

void	ft_lstadd_back(t_commands **lst, t_commands *new)
{
	t_commands	*ptr;

	if (!*lst)
		ft_lstadd_front(lst, new);
	else
	{
		ptr = ft_lstlast((*lst));
		ptr->next = new;
	}
}

void	ft_freelst(void ***s1, void **s2)
{
	if (!(**s1))
		free (**s1);
	**s1 = NULL;
	if (!(*s2))
		free (*s2);
	*s2 = NULL;
}

void	ft_lstclear(t_commands **tofree)
{
	t_commands	*tmp;

	while (*tofree)
	{
		tmp = (*tofree);
		*tofree = (*tofree)->next;
		ft_freelst((void ***)&(tmp->cmd), (void **)&(tmp->pathcmd));
		tmp->next = NULL;
		free(tmp);
	}
}