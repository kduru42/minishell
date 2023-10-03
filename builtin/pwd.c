/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:20 by btekinli          #+#    #+#             */
/*   Updated: 2023/10/03 21:09:29 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Bu fonksiyon "print working directory (pwd)" adlı minik bir shell uygulamasının 
parçası olabilir. Bu fonksiyon, kullanıcının mevcut çalışma dizinini 
(current working directory) ekrana yazdırır ve sonrasında uygulamanın çalışmasını 
sonlandırır. Eğer fonksiyon çalışması sırasında hata oluşursa, "minishell" hatası 
ekrana yazdırılır ve errno değişkeni kullanılarak uygulamanın çalışması sonlandırılır.
*/
void	builtin_pwd(t_shell *ms)
{
	char	*result;

	result = getcwd((void *)0, 0);
	if (!result)
		perror("minishell ");
	else
		printf("%s\n", result);
	free(result);
	if (!is_parent(ms))
		exit(errno);
}
