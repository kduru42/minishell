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

int main()
{
	t_shell	*ms;
    char    *input;

	ms = (t_shell *)malloc(sizeof(t_shell));
	init_data(ms);
    while (1) {
        write(1, "\033[32m", 5);
		input = readline("$ ");
		write(1, "\033[0m", 4);
		ms->input = ft_strdup(input);
		lex_command(ms);
		lexer(ms);
		
		t_process *iter;
		int i = 0;
		iter = ms->process;
		printf("%s\n%s\n%s\n", iter->execute[0], iter->execute[1], iter->redirects[0]);
		iter = iter->next;
    }

    return (0);
}