/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:22 by btekinli          #+#    #+#             */
/*   Updated: 2023/10/03 21:12:30 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
`remove_env` fonksiyonu, belirtilen bir değişkenin ortam değişkeni dizisinden 
kaldırılmasını sağlar. Fonksiyon, belirtilen değişkenin ismini alır ve ortam değişkeni 
dizisinde bulunan tüm girişleri kontrol eder. Eğer bulunan giriş belirtilen 
değişkene eşitse, o giriş ortam değişkeni dizisinden silinir ve kalan girişler 
yeni bir ortam değişkeni dizisi oluşturulur.
*/
void	remove_env(t_shell *ms, char *data)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = (char **)malloc(sizeof(char *) * (env_len(ms) + 1));
	while (ms->env[i])
	{
		if (ft_strncmp(ms->env[i], data, ft_strlen(data)))
		{
			new_env[j] = ft_strdup(ms->env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	free_array(ms->env);
	ms->env = new_env;
}

/*
Bu C dilinde bir fonksiyondur ve "unset" komutunun işlevini yerine getirir. Bu fonksiyon, 
girdi olarak verilen değişkenleri ortam değişkenlerinden kaldırır ve set_paths() fonksiyonunu 
çağırarak yolun güncellenmesini sağlar. Eğer fonksiyon çalışan bir ebeveyn işlem değilse, 
başarıyla çıkış yapar (EXIT_SUCCESS).
*/
void	builtin_unset(t_shell *ms, char **input)
{
	char	*data;

	input++;
	while (*input)
	{
		data = ft_strjoin(*input, "=");
		remove_env(ms, data);
		free(data);
		input++;
	}
	set_paths(ms);
	if (!is_parent(ms))
		exit (EXIT_SUCCESS);
}
