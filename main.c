/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:06:17 by kduru             #+#    #+#             */
/*   Updated: 2023/08/11 20:06:17 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **arg, char **env)
{
	t_shell	*ms;
    char    *input;

	ms = (t_shell *)malloc(sizeof(t_shell));
	init_data(ms, env);
    while (ac && arg) {
        write(1, "\033[32m", 5);
		input = readline("$ ");
		write(1, "\033[0m", 4);
		handle_quotes(ms, input);
 		tokenizer(ms, ms->input);
		lexer(ms);
		run_builtin(ms, ms->process->execute);
		
/* 		t_process *iter;
		iter = ms->process;
		printf("%s\n%s\n", iter->execute[0], iter->execute[1]);
		printf("%s\n%s\n", iter->redirects[0], iter->redirects[1]);  */ 
	}
	free_data(ms);
    return (0);
}