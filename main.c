/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:53:50 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/06 19:40:22 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		exit_msg("Pipe creation failed", NULL);
}

int	main(int ac, char **av)
{
	int		pipefd[2];
	char	*argv[2];

	argv[0] = "-l";
	argv[1] = NULL;
	execve("/bin/wc", argv, NULL);
	exit(EXIT_SUCCESS);
	parsing(ac, av);
	make_pipe(pipefd);
	pipex(av, pipefd);
	return (0);
}
