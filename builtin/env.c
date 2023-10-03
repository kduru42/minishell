/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:14 by btekinli          #+#    #+#             */
/*   Updated: 2023/10/03 21:02:03 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Bu fonksiyon sistem ortam değişkenlerini yazdırır. "g_ms.env" global bir dizi 
olarak tanımlanmış ortam değişkenlerini içerir ve "env" pointerı bu diziyi 
gösterir. Her bir ortam değişkeni ekrana yazdırılır ve sonra bir sonraki ortam 
değişkenine geçilir. Fonksiyon sonunda, "is_parent()" fonksiyonu çağrılır ve çıktı 
eğer parent prosesse aitse "EXIT_SUCCESS" ile çıkılır.
*/
void	builtin_env(t_shell *ms)
{
	char	**env;

	env = ms->env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	if (!is_parent(ms))
		exit (EXIT_SUCCESS);
}
