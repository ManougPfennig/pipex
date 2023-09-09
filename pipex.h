/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:24:47 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/09 19:40:46 by mapfenni         ###   ########.fr       */
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

void	parsing(int ac, char **av);
void	exit_msg(char *str, char *str2);
void	pipex(char **av, int pipefd[2], int filesfd[2], int saved[2]);
void	check_execve(char *path, char **arg, int *error, int saved[2]);
void	arg_prep(char **path, char ***arg, char *split);
void	do_dup2(int fd, int replaced);
pid_t	do_fork(void);
int		do_open(char *str, int oflag);
void	make_pipe(int pipefd[2]);
void	ft_free_tab(char **tab, char *str);
char	*ft_lastav(char **av);

#endif