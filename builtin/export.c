/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:18 by btekinli          #+#    #+#             */
/*   Updated: 2023/10/03 21:09:11 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
`env_len` fonksiyonu `g_ms.env` adlı global bir dizide bulunan ortam değişkenlerinin 
sayısını hesaplamak için kullanılır. İşlevi, `g_ms.env` dizisindeki eleman sayısını 
bulmak için bir döngü oluşturmak ve sonunda döngü başı ve sonu arasındaki farkın 
hesaplanmasıdır. Bu hesaplanan fark, dizinin eleman sayısını verir ve bu, fonksiyonun 
döndürmek istediği değerdir.
*/
int	env_len(t_shell *ms)
{
	char	**env;

	env = ms->env;
	while (*env)
		env++;
	return (env - ms->env);
}

/*
`check_env` fonksiyonu, verilen bir string'in ortam değişkeni olarak kullanılabilir 
olup olmadığını kontrol eder. Ortam değişkeni stringi, bir '=' işareti ile başlamalı 
ve başında ve sonunda boşluk karakteri bulunmamalıdır. Bu fonksiyon, bir stringin ortam 
değişkeni olarak geçerli olup olmadığını, `TRUE` veya `FALSE` değerleri ile belirler.
*/
int	check_env(char *str)
{
	char	*head;

	head = ft_strchr(str, '=');
	if (!head)
		return (FALSE);
	if (head == str)
		return (FALSE);
	while (*str)
	{
		if (is_whitespace(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

/*
Bu fonksiyon, belirtilen dizgi (str) parametresini, çalışma zamanı ortamına ekler. 
G_ms global değişkeni, programın çalışma zamanı ortamını tutan bir yapıdır ve add_env 
fonksiyonu bu yapıya belirtilen dizgiyi ekler. Bu fonksiyon, eklenecek dizginin geçerli 
olup olmadığını kontrol eder ve geçerli ise, g_ms yapısındaki ortam dizisini günceller 
ve yeni dizgi ekler.
*/
void	add_env(t_shell *ms, char *str)
{
	int		i;
	char	**env;
	char	**new_env;

	i = 0;
	env = ms->env;
	new_env = (char **)malloc(sizeof(char **) * (env_len(ms) + 2));
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	free_array(ms->env);
	ms->env = new_env;
}

/*
`is_include` fonksiyonu, verilen bir stringin (`str`) g_ms.env değişkenindeki bir ortam değişkeni 
listesinde var olup olmadığını kontrol eder. Eğer değişken listesinde varsa, bu değişkenin listedeki 
sırasını (index) döndürür. Yoksa -1 döndürür.
*/
int	is_include(t_shell *ms, char *str)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = ms->env;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}

/*
"builtin_export" fonksiyonu, komut satırından "export" komutu verildiğinde çalışan bir iç komuttur. 
Bu fonksiyon, belirtilen ortam değişkenini kontrol eder ve eğer geçerli bir değişken ise, mevcut değişken 
listesinde var mı yok mu kontrol eder. Eğer mevcut ise, o değişkenin değeri güncellenir. Değilse, 
yeni bir değişken olarak eklenir. "set_paths" fonksiyonu sonrasında çalışır ve çalışma dizininde 
değişiklik yapmak için kullanılabilir.
*/
void	builtin_export(t_shell *ms, char **input)
{
	int		pos;
	char	*tmp;

	input++;
	while (*input)
	{
		if (check_env(*input))
		{
			pos = is_include(ms, *input);
			if (pos != -1)
			{
				tmp = ms->env[pos];
				ms->env[pos] = ft_strdup(*input);
				free(tmp);
			}
			else
				add_env(ms, *input);
		}
		input++;
	}
	set_paths(ms);
	if (!is_parent(ms))
		exit (EXIT_SUCCESS);
}
