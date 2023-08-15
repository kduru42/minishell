/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:57:35 by kduru             #+#    #+#             */
/*   Updated: 2023/08/15 20:19:47 by kduru            ###   ########.fr       */
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
	ms->process = NULL;
}

t_token	*token_constructor(char *str, enum e_ttype type)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->type = type;
	token->str = str;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

t_process	*process_constructor(void)
{
	t_process	*process;

	process = (t_process *)malloc(sizeof(t_process));
	pipe(process->fd);
	process->pid = -1;
	process->execute = (char **)malloc(sizeof(char *));
	process->redirects = (char **)malloc(sizeof(char *));
	process->prev = NULL;
	process->next = NULL;
	return (process);
}

void	ft_process_addback(t_process **processes, t_process *to_add)
{
	t_process	*tmp;

	tmp = *processes;
	if (*processes == NULL)
	{
		*processes = to_add; 
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
	tmp->next->prev = tmp;
	return ;
}