/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:23 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/05 18:57:44 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd != -1)
		close(fd);
	else
		exit_msg("could not open ", file);
	return (1);
}

void	parsing(int ac, char **av)
{
	if (ac != 5)
		exit_msg("Unvalid amount of arguments", NULL);
	check_open(av[1]);
	check_open(av[4]);
}