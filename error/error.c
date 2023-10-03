/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:27:29 by kduru             #+#    #+#             */
/*   Updated: 2023/10/03 20:28:13 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	token_err(int type)
{
	char	*red;

	if (type == HERE_DOC)
		red = "<<";
	else if (type == RED_INPUT)
		red = "<";
	else if (type == RED_OUTPUT)
		red = ">";
	else if (type == RED_APPEND)
		red = ">>";
	else if (type == PIPE)
		red = "|";
	else
		red = "newline";
	errno = 258;
	write(2, "minishell: syntax error near unexpected token '", 47);
	write(2, red, ft_strlen(red));
	write(2, "'\n", 2);
}