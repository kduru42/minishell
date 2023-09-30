/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:03:53 by kduru             #+#    #+#             */
/*   Updated: 2023/10/01 00:12:58 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char**	push_to_array(char **arr, char *new_arr)
{
	char	**tmp_arr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (arr && arr[len])
		len++;
	tmp_arr = (char **)malloc(sizeof(char *) * (len + 2));
	while (i < len)
	{
		tmp_arr[i] = arr[i];
		i++;
	}
	tmp_arr[len] = new_arr;
	free(arr);
	return (tmp_arr);
}

int	get_processes(t_token **token, t_process *process)
{
	if ((*token)->type == STRING)
		process->execute = push_to_array(process->execute, (*token)->str);
	else
	{
		process->redirects = push_to_array(process->redirects, (*token)->str);
		*token = (*token)->next;
		process->redirects = push_to_array(process->redirects, (*token)->str);
	}
	return (TRUE);
}

int	lexer(t_shell *ms)
{
	t_token		*token;
	t_process	*process;
	
	token = ms->token;
	while (token)
	{
		if (token->type == PIPE || token->prev == NULL)
		{
			process = process_constructor();
			ft_process_addback(&ms->process, process);
		}
		get_processes(&token, process);
		token = token->next;
	}
	return (TRUE);
}