/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:34:45 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/07 13:20:53 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac == 5)
	{
		if (!access(av[1], R_OK))
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
