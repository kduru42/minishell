/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:22:36 by btekinli          #+#    #+#             */
/*   Updated: 2023/10/03 21:09:55 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Bu fonksiyon "command" değişkeninde verilen komutun, shell tarafından yerleşik 
olarak desteklenen bir komut olup olmadığını kontrol eder. Her bir yerleşik 
komut için bir dönen değer vardır. Örneğin, "cd" komutu için CD değeri, "exit" 
komutu için EXIT değeri vb. Eğer verilen komut yerleşik bir komut değilse, 
fonksiyon 0 döner.
*/
int	is_builtin(char *command)
{
	if (ft_strcmp(command, "cd"))
		return (CD);
	if (ft_strcmp(command, "env"))
		return (ENV);
	if (ft_strcmp(command, "pwd"))
		return (PWD);
	if (ft_strcmp(command, "echo"))
		return (ECHO);
	if (ft_strcmp(command, "exit"))
		return (EXIT);
	if (ft_strcmp(command, "unset"))
		return (UNSET);
	if (ft_strcmp(command, "export"))
		return (EXPORT);
	return (0);
}

/*
Bu fonksiyon, çalıştırılmak istenen komutun bir iç yapı komutu olup olmadığını belirler 
ve eğer iç yapı komutu ise, o komutun çalışmasını sağlar. Örneğin, çalıştırılmak istenen 
komut "cd" ise, "builtin_cd" fonksiyonu çağrılır ve klasör değiştirme işlemi yapılır.
*/
void	run_builtin(t_shell *ms, char **execute)
{
	int	type;

	type = is_builtin(execute[0]);
	if (type == CD)
		builtin_cd(ms, execute);
	if (type == ENV)
		builtin_env(ms);
	if (type == PWD)
		builtin_pwd(ms);
	if (type == ECHO)
		builtin_echo(ms, execute);
	if (type == EXIT)
		builtin_exit(execute);
	if (type == UNSET)
		builtin_unset(ms, execute);
	if (type == EXPORT)
		builtin_export(ms, execute);
}
