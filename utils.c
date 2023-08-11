/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:10:32 by kduru             #+#    #+#             */
/*   Updated: 2023/08/11 21:19:40 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *string)
{
	char	*arr;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (string[size])
		size++;
	arr = (char *)malloc(size + 1);
	if (!arr)
		return (NULL);
	while (string[i])
	{
		arr[i] = string[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

void	ft_lstadd_back(t_token **token, char *string)
{
	t_token	*tmp;

	if (*token == NULL)
	{
		*token = (t_token *)malloc(sizeof(t_token));
		(*token)->str = ft_strdup(string);
		(*token)->next = NULL;
		(*token)->prev = NULL;
		return ;
	}
	tmp = *token;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_token *)malloc(sizeof(t_token));
	tmp->next->str = ft_strdup(string);
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
	return ;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	subs = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!subs)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len)
		{
			subs[i] = s[start];
			i++;
			start++;
		}
	}
	subs[i] = 0;
	return (subs);
}
