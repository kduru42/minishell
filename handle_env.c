/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:31:14 by kduru             #+#    #+#             */
/*   Updated: 2023/10/01 01:35:22 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*split_env(char *str)
{
	while (*str != '=')
		str++;
	str++;
	return (ft_strdup(str));
}

void	set_env(t_shell *ms, char **env)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (env[size])
		size++;
	ms->env = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size)
		ms->env[i] = ft_strdup(env[i]);
	return ;
}

char	*get_env(t_shell *ms, char *str)
{
	size_t	len;
	char	**env;
	char	*new_str;

	env = ms->env;
	new_str = ft_strjoin(str, "=");
	len = ft_strlen(new_str);
	while (*env)
	{
		if (!ft_strncmp(*env, new_str, len))
		{
			free(new_str);
			return (split_env(*env));
		}
		env++;
	}
	free(new_str);
	return (malloc(sizeof(char *) * 1));
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
