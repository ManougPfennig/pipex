/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:23 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/06 15:16:49 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_open(char **av)
{
	int	fd;

	if (access(av[1], F_OK) != 0)
		exit_msg("Input file does not exist -> ", av[1]);
	if (access(av[4], F_OK) != 0)
		exit_msg("Input file does not exist -> ", av[4]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_msg("Cannot open input file -> ", av[1]);
	close(fd);
	fd = open(av[4], O_RDONLY);
	if (fd == -1)
		exit_msg("Cannot open output file -> ", av[4]);
	close(fd);
}

void	parsing(int ac, char **av)
{
	if (ac != 5)
		exit_msg("Unvalid amount of arguments", NULL);
	check_open(av);
}
