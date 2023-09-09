/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:20:04 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/09 19:29:56 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	arg_prep(char **path, char ***arg, char *split)
{
	*arg = ft_split(split, ' ');
	*path = ft_strjoin("/bin/", *arg[0]);
}