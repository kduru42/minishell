/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:24:36 by kduru             #+#    #+#             */
/*   Updated: 2023/10/03 21:53:16 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_data(t_shell *ms)
{
	free_token(ms);
	free_process(ms);
	free(ms->history);
	free(ms->input);
	free(ms);
}

void	free_token(t_shell *ms)
{
	t_token		*tmp;
	t_token		*token;

	token = ms->token;
	while (token)
	{
		free(token->str);
		token = token->next;
	}
	token = ms->token;
	while (token)
	{
		tmp = token;
		token = token->next;
		free(tmp);
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_process(t_shell *ms)
{
	t_process	*tmp;
	t_process	*process;

	process = ms->process;
	if (!process)
		return ;
	while (process)
	{
		free_array(process->execute);
		free_array(process->redirects);
		tmp = process;
		process = process->next;
		free(tmp);
	}
}
