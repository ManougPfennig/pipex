/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:24:47 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/06 19:07:58 by mapfenni         ###   ########.fr       */
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
void	pipex(char **av, int pipefd[2]);
char	*ft_lastav(char **av);

#endif