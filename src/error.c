/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:30:12 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/05 18:52:07 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exit_msg(char *str, char *str2)
{
	ft_printf("Error : %s", str);
	if (str2)
		ft_printf("%s", str2);
	exit(EXIT_FAILURE);
}