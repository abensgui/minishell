/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:09:28 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/06 23:57:33 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_file
{
	int				fd;
	int				token;
	char			*name;
	struct s_file	*next;

}			t_file;

typedef struct s_data
{
	char			**cmd;
	t_file			*file;
	char			**lim;
	struct s_data	*next;
}			t_data;

typedef struct s_env
{
	void			*key;
	void			*value;
	struct s_env	*next;
}			t_env;

typedef struct s_global
{
	t_env		*env_list;
	long long	exit_status;
	int			**fd;
	int			sig;
}			t_global;

t_global	g_global;

char	*ft_strjoin(char *s1, char c);
char	*ft_strdup(char *sr);
void	ft_lstadd_back(t_file **alst, t_file *new);
t_file	*ft_lstnew(char *content, int token);
char	*ft_join(char *s1, char *s2);
char	*ft_dqoute(char *str, int *i);
char	*ft_qoute(char *str, int *i);
char	**ft_resize(char **str, char *str1);
t_file	*ft_redi(char *str, int *i, int token);
char	*ft_cmd(char *str, int *i);
char	*ft_cmd1(char *str, int *i);
int		ft_error(char *str);
char	*ft_expand(char *str, int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
t_file	*ft_herdoc(char *str, int *i, int token);
char	*cat_str(char *str, int *i);
int		error_quote(char *str, int *i);
int		error_dquote(char *str, int *i);
int		error_redi_in(char *str, int *i);
int		error_redi_ou(char *str, int *i);
int		error_pipe(char *str, int *i);
void	free_data(t_data *data);
t_data	*ft_parce(char *str, int c);
int		check_redi(t_data **data, char *str, int *i);
void	ft_execute(t_data *data, char **t);
int		ft_builtins(t_data *data);
void	command_echo(t_data *data);
int		command_cd(char *path);
void	command_pwd(void);
void	command_exit(t_data *data);
void	command_env(char **env);
void	ft_lstadd_back_ex(t_env **lst, t_env *new);
t_env	*ft_lstnew_ex(void *key, void *value);
char	*ft_strchr(const char *s, int c);
void	command_export(t_data *data);
char	*ft_strjoin_env(char const *s1, char const *s2);
void	command_unset(t_data *data);
char	*ft_getenv(char *s);
char	**ft_heredoc(t_data *data);
char	*ft_itoa(int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_lstsize(t_data *lst);
void	ft_execve(t_data *data);
void	ft_pipes(t_data *data, int **fd, int i);
char	**ft_split(char const *s, char c);
int		ft_lstsize_env(t_env *lst);
int		ft_redirections(t_data *data, char **t);
int		ft_atoi(char *str);
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	ft_childs(int **fd, int j, int i);
int		check_all_key(char *s);
int		check_start_key(char *s);
int		cmp(char *s1, char *s2);
void	ft_lstadd_back_export(t_env *new);
t_env	*ft_lstnew_export(void *key, void *value);
void	ft_overwrite(char *data, char *value);
void	ft_sort(void);
int		is_not_in_env(char *s);
int		is_there_value(char *s, t_env *env);
void	print_export_list(t_env *head);
char	*return_value(char *s);
int		strfind(char *s, char c);
void	free_table(char **str);
void	key_without_plus(char *key, char *value, t_data *data, int i);
void	key_with_plus(char *key, char *value, t_data *data, int i);
size_t	ft_strlen(const char *str);
char	*sndup(char *src, size_t n);

#endif
