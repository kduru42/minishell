/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:00:22 by kduru             #+#    #+#             */
/*   Updated: 2023/08/13 20:03:45 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_string(t_shell *ms, int pos, int start)
{
	char	*str;

	str = ft_substr(ms->input, start, pos - start);
	ft_lstadd_back(&ms->token, token_constructor(str, STRING));
	return ;
}

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

void	parse_operator(t_shell *ms, int pos, int start)
{
	char	*str;
	
	str = ft_substr(ms->input, start, pos - start);
	if (which_operator(str) == HERE_DOC)
		ft_lstadd_back(&ms->token, token_constructor(str, HERE_DOC));
	else if (which_operator(str) == RED_APPEND)
		ft_lstadd_back(&ms->token, token_constructor(str, RED_APPEND));
	if (which_operator(str) == RED_INPUT)
		ft_lstadd_back(&ms->token, token_constructor(str, RED_INPUT));
	if (which_operator(str) == PIPE)
		ft_lstadd_back(&ms->token, token_constructor(str, PIPE));
	return ;
}
