/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:53:50 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/08 17:47:49 by mapfenni         ###   ########.fr       */
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

int	do_open(char *str, int oflag)
{
	int	fd;

	fd = open(str, oflag);
	if (fd == -1)
		exit_msg("Failed to open file", str);
	return (fd);
}

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
	if (pipex(av, pipefd, filesfd, saved))
	{
		do_dup2(saved[0], STDIN_FILENO);
		do_dup2(saved[1], STDOUT_FILENO);
		exit_msg("Unvalid command used", NULL);
	}
}
