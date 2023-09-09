/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:53:50 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/09 19:05:13 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int		pipefd[2];
	int		filesfd[2];
	int		saved[2];

	parsing(ac, av);
	make_pipe(pipefd);
	filesfd[0] = do_open(av[1], O_RDONLY);
	filesfd[1] = do_open(ft_lastav(av), O_WRONLY);
	saved[0] = dup(STDIN_FILENO);
	saved[1] = dup(STDOUT_FILENO);
	pipex(av, pipefd, filesfd, saved);
}
