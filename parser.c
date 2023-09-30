/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:00:22 by kduru             #+#    #+#             */
/*   Updated: 2023/10/01 00:06:02 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_ttype which_operator(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '<' && str[1] == '<')
		return (HERE_DOC);
	if (str[0] == '>' && str[1] == '>')
		return (RED_APPEND);
	if (str[0] == '<')
		return (RED_INPUT);
	if (str[0] == '>')
		return (RED_OUTPUT);
	if (str[0] == '|')
		return (PIPE);
	return (0);
}


void	tokenizer(t_shell *ms, char *str)
{
	while (*str)
	{
		if (which_operator(str) == HERE_DOC)
			str += ft_lstadd_back(&ms->token, token_constructor(ft_strdup("<<"), HERE_DOC), 2);
		else if (which_operator(str) == RED_APPEND)
			str += ft_lstadd_back(&ms->token, token_constructor(ft_strdup(">>"), RED_APPEND), 2);
		else if (which_operator(str) == RED_INPUT)
			str += ft_lstadd_back(&ms->token, token_constructor(ft_strdup("<"), RED_INPUT), 1);
		else if (which_operator(str) == RED_OUTPUT)
			str += ft_lstadd_back(&ms->token, token_constructor(ft_strdup(">"), RED_OUTPUT), 1);
		else if (which_operator(str) == PIPE)
			str += ft_lstadd_back(&ms->token, token_constructor(ft_strdup("|"), PIPE), 1);
		else
			lex_command(ms, &str);
	}
	return ;
}

