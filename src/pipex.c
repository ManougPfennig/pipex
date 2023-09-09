/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:07:06 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/09 19:40:53 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_command(char *path, char **arg, int pipefd[2], int filesfd[2])
{
	do_dup2(filesfd[0], STDIN_FILENO);
	do_dup2(pipefd[1], STDOUT_FILENO);
	if (execve(path, arg, NULL) == -1)
		exit(EXIT_FAILURE);
}

void	pipe_loop(char *path, char **arg, int pipefd[2], int saved[2])
{
	do_dup2(pipefd[0], STDIN_FILENO);
	do_dup2(pipefd[1], STDOUT_FILENO);
	if (execve(path, arg, NULL) == -1)
	{
		do_dup2(saved[0], STDIN_FILENO);
		do_dup2(saved[1], STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	last_command(char *path, char **arg, int pipefd[2], int filesfd[2])
{
	do_dup2(pipefd[0], STDIN_FILENO);
	do_dup2(filesfd[1], STDOUT_FILENO);
	if (execve(path, arg, NULL) == -1)
		exit(EXIT_FAILURE);
}

void	pipex(char **av, int pipefd[2], int filesfd[2], int saved[2])
{
	char	**arg;
	char	*path;
	int		error;
	pid_t	pid;
	int		i;

	i = 2;
	arg_prep(&path, &arg, av[i]);
	pid = do_fork();
	if (pid == 0)
		first_command(path, arg, pipefd, filesfd);
	check_execve(path, arg, &error, saved);
	while (++i && av[i + 2] != NULL)
	{
		arg_prep(&path, &arg, av[i]);
		pid = do_fork();
		if (pid == 0)
			pipe_loop(path, arg, pipefd, saved);
		check_execve(path, arg, &error, saved);
	}
	arg_prep(&path, &arg, av[i]);
	pid = do_fork();
	if (pid == 0)
		last_command(path, arg, pipefd, filesfd);
	check_execve(path, arg, &error, saved);
}
