/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:10:32 by kduru             #+#    #+#             */
/*   Updated: 2023/09/30 23:38:19 by kduru            ###   ########.fr       */
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

int	ft_lstadd_back(t_token **token, t_token *to_add, int plus)
{
	t_token	*tmp;

	tmp = *token;
	if (*token == NULL)
		*token = to_add;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_add;
		tmp->next->prev = tmp;		
	}
	return (plus);
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


int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}
