/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:31:14 by kduru             #+#    #+#             */
/*   Updated: 2023/10/03 20:21:31 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
