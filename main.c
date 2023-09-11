/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:53:50 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/11 23:03:59 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	t_fd	*fd;
	t_fd	data;

	fd = &data;
	parsing(ac, av, fd);
	make_pipe(fd->pipe);
	make_pipe(fd->pipe2);
	fd->test = NULL;
	fd->infile = do_open(av[1], O_RDONLY);
	fd->outfile = do_open(ft_lastav(av), O_WRONLY);
	fd->saved[0] = dup(STDIN_FILENO);
	fd->saved[1] = dup(STDOUT_FILENO);
	pipex(av, fd);
	ft_free_tab(fd->path, NULL);
}
