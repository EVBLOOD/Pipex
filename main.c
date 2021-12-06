/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:34:45 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/06 16:18:57 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac >= 5)
	{
		if (ac == 6 && !ft_strcmp(av[1], "here_doc"))
		{
			if (pipexdel2(ac, av, env))
				exit (1);
		}
		else if (!access(av[1], R_OK))
		{
			if (pipex(ac, av, env))
				exit (1);
		}
		else
		{
			write (2, "file does not exist!", 20);
			exit (1);
		}
	}
	else
	{
		write (2, "invalid inputs.", 15);
		return (1);
	}
	return (0);
}
