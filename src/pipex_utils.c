/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:45:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/09 19:39:51 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	do_dup2(int fd, int replaced)
{
	if (dup2(fd, replaced) == -1)
		exit_msg("dup2 failed", NULL);
}

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

void	check_execve(char *path, char **arg, int *error, int saved[2])
{
	ft_free_tab(arg, path);
	waitpid(0, error, 0);
	if (*error)
	{
		do_dup2(saved[0], STDIN_FILENO);
		do_dup2(saved[1], STDOUT_FILENO);
		exit_msg("Unvalid command used\n", NULL);
	}
}
