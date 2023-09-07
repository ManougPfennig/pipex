/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:30:12 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/07 16:51:15 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_tab(char **tab, char *str)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	if (str)
		free(str);
	tab = NULL;
	str = NULL;
}

void	exit_msg(char *str, char *str2)
{
	ft_printf("Error : %s", str);
	if (str2)
		ft_printf("%s", str2);
	exit(EXIT_FAILURE);
}