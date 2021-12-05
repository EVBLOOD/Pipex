/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:34:45 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/05 23:31:01 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac >= 5 && !access(av[1], R_OK))
	{
		if (pipex(ac, av, env))
		{
			write (1, "something dosn't same to work", 29);
			return (1);
		}
	}
	else if (ac == 6 && !ft_strcmp(av[1], "here_doc"))
	{
		if (pipexdel2(ac, av, env))
		{
			write (1, "something dosn't same to work", 29);
			return (1);
		}
	}
	else
	{
		write (1, "Please recheck the inputs.", 25);
		return (1);
	}
	return (0);
}