/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:23 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/11 16:26:51 by mapfenni         ###   ########.fr       */
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
	int	fd;

	if (ft_strlen(str) == 0)
		exit_msg("Invalid output name", NULL, NULL);
	fd = open(str, O_CREAT, 0666);
	close(fd);
}

int	check_files(char **av)
{
	int	fd;

	if (access(av[1], F_OK) != 0)
		exit_msg("Input file does not exist -> ", av[1], NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_msg("Cannot open input file -> ", av[1], NULL);
	close(fd);
	if (access(ft_lastav(av), F_OK) != 0)
		return (1);
	fd = open(ft_lastav(av), O_RDONLY | O_TRUNC);
	if (fd == -1)
		exit_msg("Cannot write to output file -> ", ft_lastav(av), NULL);
	close(fd);
	return (0);
}

int	check_commands(char *av, t_fd fd)
{
	int		i;
	int		check;
	char	*path;
	char	**arg;

	i = 0;
	check = 0;
	path = NULL;
	arg = ft_split(av, ' ');
	while (fd.path[i])
	{
		path = ft_strjoin(fd.path[i], arg[0]);
		if (access(path, F_OK) == 0)
			check++;
		i++;
		ft_free_tab(NULL, path);
	}
	ft_free_tab(arg, NULL);
	if (check)
		return (1);
	return(0);
}

void	parsing(int ac, char **av, t_fd fd)
{
	int	i;

	i = 0;
	if (ac != 5)
		exit_msg("Unvalid amount of arguments", NULL, NULL);
	if (check_files(av))
		touch_output(ft_lastav(av));
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
			exit_msg("Unvalid argument length", NULL, NULL);
		i++;
	}
	fd.path = ft_split("/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:\
	/sbin/:/bin/:/usr/games/:/usr/local/games/:/snap/bin/:/snap/bin/", ':');
	if (check_commands(av[2], fd) == 0)
		exit_msg("Unvalid command used", NULL, fd.path);
	if (check_commands(av[3], fd) == 0)
		exit_msg("Unvalid command used", NULL, fd.path);
}
