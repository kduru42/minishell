/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:06:10 by kduru             #+#    #+#             */
/*   Updated: 2023/10/03 20:14:56 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

void	skip_whitespace(char **str, char **head)
{
	while (**str && is_whitespace(**str))
		(*str)++;
	*head = *str;
}

void	checker(char **str)
{
	while (**str)
	{
		if (is_whitespace(**str))
			break ;
		if (which_operator(*str))
			break ;
		(*str)++;
	}
}

void	lex_command(t_shell *ms, char **str)
{
	int		len;
	char	*head;
	char	*token_str;

	skip_whitespace(str, &head);
	checker(str);
	len = *str - head;
	if (len > 0)
	{
		token_str = ft_substr(head, 0, len);
		ft_lstadd_back(&ms->token, token_constructor(token_str, STRING), 0);
	}	
}
