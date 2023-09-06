/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:23 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/06 14:22:06 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_open(char **av)
{
	if (access(av[1], F_OK) != 0)
		exit_msg("Cannot find input file -> ", av[1]);
	if (access(av[4], F_OK) != 0)
		exit_msg("Cannot find output file -> ", av[4]);
}

void	parsing(int ac, char **av)
{
	if (ac != 5)
		exit_msg("Unvalid amount of arguments", NULL);
	check_open(av);
}
