/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:07:06 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/08 18:18:22 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	do_dup2(int fd, int replaced)
{
	if (dup2(fd, replaced) == -1)
		exit_msg("dup2 failed", NULL);
}

void	cmd1(char **av, int pipefd[2], int fdin, int saved[2])
{
	char	**command;
	char	*path;
	pid_t	pid;

	command = ft_split(av[2], ' ');
	path = ft_strjoin("/bin/", command[0]);
	if (pid > 0)
	{
		do_dup2(fdin, STDIN_FILENO);
		do_dup2(pipefd[1], STDOUT_FILENO);
		if (execve(path, command, NULL) == -1)
		{
			ft_free_tab(command, path);
			do_dup2(saved[0], STDIN_FILENO);
			do_dup2(saved[1], STDOUT_FILENO);
			exit_msg("Unvalid command used\n", NULL);
		}
	}
	ft_free_tab(command, path);
}

void	cmd2(char **av, int pipefd[2], int fdout, int saved[2])
{
	char	**command;
	char	*path;

	command = ft_split(av[3], ' ');
	path = ft_strjoin("/bin/", command[0]);
	if (pid > 0)
	{
		do_dup2(pipefd[0], STDIN_FILENO);
		do_dup2(fdout, STDOUT_FILENO);
		if (execve(path, command, NULL) == -1)
		{
			ft_free_tab(command, path);
			do_dup2(saved[0], STDIN_FILENO);
			do_dup2(saved[1], STDOUT_FILENO);
			exit_msg("Unvalid command used\n", NULL);
		}
	}
	ft_free_tab(command, path);
}

int	pipex(char **av, int pipefd[2], int filesfd[2], int saved[2])
{
	pid_t	pid;

	pid = fork();
	cmd1(av, pipefd, filesfd[0], saved);
	do_dup2(saved[0], STDIN_FILENO);
	do_dup2(saved[1], STDOUT_FILENO);
	cmd2(av, pipefd, filesfd[1], saved)
	return (0);
}
