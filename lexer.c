/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:06:10 by kduru             #+#    #+#             */
/*   Updated: 2023/08/11 21:23:23 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lex_command(t_shell *ms)
{
	char	*str;
	int		i;
	int		start;

	i = 0;
	while (ms->input[i])
	{
		start = i;
		while (ms->input[i] != '|' && ms->input[i])
			i++;
		str = ft_substr(ms->input, start, i - start);
		ft_lstadd_back(&ms->token, str);
		if (!ms->input[i])
			return ;
		i++;
	}
	return ;
}
