/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:57:35 by kduru             #+#    #+#             */
/*   Updated: 2023/08/11 21:17:31 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_shell *ms)
{
	int	i;

	i = 0;
	ms->history = (char **)malloc(sizeof(char *));
	while (i < 100)
		ms->history[i++] = (char *)malloc(sizeof(char) * 100);
	ms->input_count = 0;
	ms->token = NULL;
}