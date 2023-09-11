/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:24:47 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/11 16:23:30 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_data {
	int		pipe[2];
	int		pipe2[2];
	int		saved[2];
	int		infile;
	int		outfile;
	char	**path;
	char	*test;
}				t_fd;

void	parsing(int ac, char **av, t_fd fd);
void	exit_msg(char *str, char *str2, char **to_free);
void	pipex(char **av, t_fd fd);
void	check_execve(char **arg, t_fd fd);
void	arg_prep(char **path, char ***arg, char *split);
void	do_dup2(int fd, int replaced);
pid_t	do_fork(void);
int		do_open(char *str, int oflag);
void	make_pipe(int pipefd[2]);
void	ft_free_tab(char **tab, char *str);
char	*ft_lastav(char **av);

#endif