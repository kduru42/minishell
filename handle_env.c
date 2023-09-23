/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:31:14 by kduru             #+#    #+#             */
/*   Updated: 2023/09/23 19:34:37 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(t_shell *ms, char **env)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (env[size])
		size++;
	while (i++ < size)
		ms->env[i] = ft_strdup(env[i]);
	return ;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	push_new_str(char **new_str, char *str)
{
	char	*temp;

	if (!(*new_str))
	{
		*new_str = ft_strdup(str);
		free(str);
		return ;
	}
	temp = *new_str;
	*new_str = ft_strjoin(*new_str, str);
	free(temp);
	free(str);
}


