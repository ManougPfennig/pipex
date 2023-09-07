/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:53:50 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/07 17:07:34 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		exit_msg("Pipe creation failed", NULL);
}

pid_t	do_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_msg("Fork creation failed", NULL);
	return (pid);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		pipefd[2];

	parsing(ac, av);
	make_pipe(pipefd);
	pid = do_fork();
	pipex(av, pipefd, pid);
	return (0);
}
