/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:07:06 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/07 18:10:10 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	do_dup2(int fd, int replaced)
{
	if (dup2(fd, replaced) == -1)
		exit_msg("Dup2 failed", NULL);
}

int	do_open(char *str, int oflag)
{
	int	fd;

	fd = open(str, oflag);
	if (fd == -1)
		exit_msg("Failed to open file", str);
	return (fd);
}

void	cmd1(char **av, int pipefd[2], int fdin)
{
	char	**command1;
	char	*path;

	do_dup2(fdin, STDIN_FILENO);
	do_dup2(pipefd[1], STDOUT_FILENO);
	command1 = ft_split(av[2], ' ');
	path = ft_strjoin("/bin/", command1[0]);
	if (execve(path, (command1 + 1), NULL) == -1)
	{
		ft_free_tab(command1, path);
		close(pipefd[0]);
		close(pipefd[1]);
		close(fdin);
		exit_msg("Unvalid command used", NULL);
	}
	ft_free_tab(command1, path);
}

void	cmd2(char **av, int pipefd[2], int fdout)
{
	char	**command2;
	char	*path;

	do_dup2(pipefd[0], STDIN_FILENO);
	do_dup2(fdout, STDOUT_FILENO);
	command2 = ft_split(av[3], ' ');
	path = ft_strjoin("/bin/", command2[0]);
	if (execve(path, (command2 + 1), NULL) == -1)
	{
		ft_free_tab(command2, path);
		close(pipefd[0]);
		close(pipefd[1]);
		close(fdout);
		exit_msg("Unvalid command used", NULL);
	}
	ft_free_tab(command2, path);
}

void	pipex(char **av, int pipefd[2], pid_t pid)
{
	int		fdin;
	int		fdout;

	fdin = do_open(av[1], O_RDONLY);
	fdout = do_open(ft_lastav(av), O_WRONLY);
	if (pid > 0)
		cmd1(av, pipefd, fdin);
	do_dup2(STDIN_FILENO, fdin);
	do_dup2(STDOUT_FILENO, pipefd[1]);
	if (pid == 0)
		cmd2(av, pipefd, fdout);
}
