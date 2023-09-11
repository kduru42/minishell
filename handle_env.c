/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:31:14 by kduru             #+#    #+#             */
/*   Updated: 2023/09/11 20:16:28 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(t_shell ms, char **env)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (env[size])
		size++;
	while (i++ < size)
		ms.env[i] = ft_strdup(env[i]);
	return ;
}


