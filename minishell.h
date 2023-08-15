/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:06:21 by kduru             #+#    #+#             */
/*   Updated: 2023/08/11 20:06:21 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/ioctl.h>

# define TRUE 1
# define FALSE 0
# define DOLLAR_OP '$'
# define DOUBLE_QUOTE '"'
# define SINGLE_QUOTE '\''
# define CHILD_PROCESS 0
# define MAIN_PROCESS 1
# define REPLACE 1
# define APPEND 0

enum e_builtin_types
{
	CD = 1,
	ENV,
	PWD,
	ECHO,
	EXIT,
	UNSET,
	EXPORT
};

enum e_ttype
{
	PIPE = 1,
	STRING,
	HERE_DOC,
	RED_INPUT,
	RED_APPEND,
	RED_OUTPUT
};

typedef struct s_token
{
	char			*str;
	enum e_ttype	type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_process
{
	pid_t				pid;
	int					fd[2];	
	int					heredoc_fd[2];
	char				**execute;
	char				**redirects;
	struct s_process	*prev;
	struct s_process	*next;
}	t_process;

typedef struct s_shell
{
	t_process	*process;
	t_token		*token;
	char		*input;
    char    	**history;
    int     	input_count;
}   t_shell;

t_process	*process_constructor(void);
t_token*	token_constructor(char *str, enum e_ttype type);
char		*ft_strdup(const char *string);
void		init_data(t_shell *ms);
void		ft_lstadd_back(t_token **token, t_token *to_add);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		lex_command(t_shell *ms);
void		parse_operator(t_shell *ms, int pos, int start);
void		parse_string(t_shell *ms, int pos, int start);
void		parse_operator(t_shell *ms, int pos, int start);
void		ft_process_addback(t_process **processes, t_process *to_add);
int			lexer(t_shell *ms);

#endif