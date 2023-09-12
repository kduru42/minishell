/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:24:23 by kduru             #+#    #+#             */
/*   Updated: 2023/09/12 17:48:01 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_count(char *str, char type)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[count] == type)
			count++;
		i++;
	}
	return (count);
}

char	*clear_quotes(char *str, int *pos, char type)
{
	char	*new_str;
	char	*result;
	int		j;
	int		i;

	(*pos)++;
	j = *pos;
	while (str[*pos] && str[*pos] != type)
		(*pos)++;
	new_str = ft_substr(str, j, *pos - j);
	result = (char *)malloc(sizeof(char) * (ft_strlen(new_str) - quote_count(new_str, type)) + 1);
	j = 0;
	i = 0;
	while (new_str[i++])
		if (new_str[i] != type)
			result[j++] = new_str[i];
	result[j] = '\0';
	return (result);
}


char	*get_new_str(char *str, int *pos)
{
	int	first;

	first = *pos;
	while (str[*pos] && str[*pos] != DOUBLE_QUOTE && str[*pos] != SINGLE_QUOTE)
		(*pos)++;
	return (ft_substr(str, first, *pos - first));
}

void handle_quotes(t_shell *ms, char *str)
{
	char	*last;
	char	*new_str;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == SINGLE_QUOTE)
			new_str = clear_quotes(str, &i, SINGLE_QUOTE);
		else if (str[i] == DOUBLE_QUOTE)
			new_str = clear_quotes(str, &i, DOUBLE_QUOTE);
		else
			new_str = get_new_str(str, &i);
		push_new_str(&last, new_str);
	}
	free(str);
	ms->input = ft_strdup(last);
}