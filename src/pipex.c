/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:07:06 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/06 19:57:49 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

pid_t	make_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_msg("Fork creation failed", NULL);
	return (pid);
}



void	pipex(char **av, int pipefd[2])
{
	pid_t	pid;
	int		fdin;
	int		fdout;
	char	*argv[2];

	argv[0] = "-l";
	argv[1] = NULL;
	fdin = open(av[1], O_RDONLY);
	fdout = open(ft_lastav(av), O_WRONLY);
	(void)pipefd;
	pid = make_fork();
	if (pid == 0)
	{
		dup2(fdin, STDIN_FILENO);
		execve("/bin/wc", argv, NULL);
	}
	dup2(fdout, STDOUT_FILENO);
}
