/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:24:36 by kduru             #+#    #+#             */
/*   Updated: 2023/08/21 20:26:45 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

void	free_data(t_shell *ms)
{
	free(ms->history);
	free(ms->input);
	free(ms->process);
	free(ms->token);
	free(ms);
}