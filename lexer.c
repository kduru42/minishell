/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:06:10 by kduru             #+#    #+#             */
/*   Updated: 2023/09/12 18:02:13 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_whitespace(t_shell *ms)
{
	char	*temp;

	temp = ms->input;
	while (*temp == ' ')
		temp++;
	ms->input = temp;
	return ;
}

int	check_operator(char to_control)
{
	if (to_control == '<' || to_control == '>' || to_control == '|' || to_control == '-')
		return (1);
	else
		return (0);
}

void	skip_operators(char *str, int *pos)
{
	while (str[*pos] == '<' || str[*pos] == '>' || str[*pos] == '|')
		(*pos)++;
	return ;
}

void	lex_command(t_shell *ms)
{
	int		i;
	int		start;

	i = 0;
	skip_whitespace(ms);
	while (ms->input[i])
	{
		start = i;
		while ((!check_operator(ms->input[i]) && ms->input[i] != ' ') && ms->input[i])
			i++;
		parse_string(ms, i, start);
		start = i;
		if (ms->input[i] == '-')
		{
			while (ms->input[i] != ' ')
				i++;
			parse_string(ms, i, start);
			i++;
			start = i;
		}
		skip_operators(ms->input, &i);
		parse_operator(ms, i, start);
		if (!ms->input[i])
			return ;
		i++;
	}
	return ;
}



