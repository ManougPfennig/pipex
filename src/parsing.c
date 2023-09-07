/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:23 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/07 18:28:08 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_lastav(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		i++;
	return (av[i - 1]);
}

void	touch_output(char *str)
{
	pid_t	pid;
	char	*cmd[2];

	ft_printf("making file");
	if (ft_strlen(str) == 0)
		exit_msg("Invalid output name", NULL);
	cmd[0] = str;
	cmd[1] = NULL;
	pid = fork();
	if (pid > 0)
	{
		if (execve("/bin/touch", cmd, NULL) == -1)
			exit_msg("File creation failed", NULL);
	}
	else
		return ;
}

int	check_files(char **av)
{
	int	fd;

	if (access(av[1], F_OK) != 0)
		exit_msg("Input file does not exist -> ", av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_msg("Cannot open input file -> ", av[1]);
	close(fd);
	if (access(ft_lastav(av), F_OK) != 0)
		return (1);
	fd = open(ft_lastav(av), O_RDONLY);
	if (fd == -1)
		exit_msg("Cannot open output file -> ", ft_lastav(av));
	close(fd);
	return (0);
}

void	parsing(int ac, char **av)
{
	if (ac != 5)
		exit_msg("Unvalid amount of arguments", NULL);
	if (check_files(av))
		touch_output(ft_lastav(av));
}
