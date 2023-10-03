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
	int			parent_pid;
	t_process	*process;
	t_token		*token;
	char		*input;
	char		**env;
    char    	**history;
	char		**paths;
    int     	input_count;
}   t_shell;

enum e_ttype	which_operator(char *str);
t_process		*process_constructor(void);
t_token*		token_constructor(char *str, enum e_ttype type);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *string);
void			init_data(t_shell *ms, char **env);
int				ft_lstadd_back(t_token **token, t_token *to_add, int plus);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			lex_command(t_shell *ms, char **str);
void			tokenizer(t_shell *ms, char *str);
void			ft_process_addback(t_process **processes, t_process *to_add);
void			set_env(t_shell *ms, char **env);
int				lexer(t_shell *ms);
void			push_new_str(char **new_str, char *str);
void			handle_quotes(t_shell *ms, char *str);
int				ft_isprint(int i);
void			parse_string(t_shell *ms, int pos, int start);
void			parse_operator(t_shell *ms, int pos, int start);
void			free_data(t_shell *ms);
char			*ft_strchr(const char *s, int i);
char			*dollar(t_shell *ms, char *str);
char			*get_env(t_shell *ms, char *str);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
void			token_err(int type);
void			free_token(t_shell *ms);
void			builtin_cd(t_shell *ms, char **input);
void			builtin_env(t_shell *ms);
void			builtin_echo(t_shell *ms, char **input);
void			builtin_exit(char **input);
void			builtin_export(t_shell *ms, char **input);
void			builtin_pwd(t_shell *ms);
void			builtin_unset(t_shell *ms, char **input);
void			run_builtin(t_shell *ms, char **execute);
int				is_parent(t_shell *ms);
int				ft_atoi(const char *str);
int				is_whitespace(char c);
void			free_array(char **arr);
char			**ft_split(char const *str, char c);
void			set_paths(t_shell *ms);
int				env_len(t_shell *ms);
void			free_process(t_shell *ms);

#endif