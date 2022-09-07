/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:59:31 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 19:24:35 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <errno.h>
# include "libft/libft.h"
# include "minishell.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <termios.h>
# include <dirent.h>

# define CD 	1
# define ECH 	2
# define ENV 	3
# define EXIT 	4
# define EXPORT 5
# define PWD 	6
# define UNSET 	7

typedef struct s_token
{
	char	*str;
	char	**arr;
	char	**infile;
	char	**outfile;
	int		*append_flag;
	int		inre_cnt;
	int		outre_cnt;
	char	*cmd;
	char	**option;
	char	**here_doc;
	int		heredoc_cnt;
	int		append_cnt;
	int		fd[2];
	int		is_pipe;
	int		in_quotes;
	char	*last_doc;
}	t_token;

typedef struct s_heredoc
{
	char	*filename;
	char	*str;
	int		fd;
	int		i;
	int		j;
	pid_t	pid;
	char	*here_doc;
	int		file_i;
	int		status;
	int		hd_idx;
}	t_heredoc;

typedef struct s_pipesplit
{
	int		inword;
	int		issep;
	size_t	i;
	size_t	cnt;
	int		inquotes;
}	t_pipesplit;

typedef struct s_lenpos
{
	int	j;
	int	i;
	int	len;
	int	pos;
}	t_lenpos;

typedef struct s_delqt
{
	int		pos;
	int		k;
	int		onecnt;
	int		twocnt;
}	t_delqt;

int	g_status;

t_token	*malloc_token(char *s, int *token_cnt);
char	**pipe_split(char const *s, char c);
int		parse_token(t_token *token, int token_cnt, char **envp, char *str);
t_token	*malloc_token(char *s, int *token_cnt);
char	**withoutq_split(char const *s, char c);
int		file_len(char **file);
void	close_and_free(t_token *token, int *fd, int index);
char	**parsing_path(char **envp);
int		token_len(t_token *token);
int		print_err(char *cmd, char *str);
void	ft_stdin(t_token *token, int index, int fd);
void	set_pipe_entry(int *fildes);
void	free_path(char **path);
int		open_infile(t_token *token, int index);
int		vaild_cmd_path(t_token *token, char **envp, int index);
void	set_pipe_exit(int *fildes);
void	ft_stdout(int fd);
int		first_pipe(t_token *token, char **envp, int index);
int		index_zero(t_token *token, char **envp, int index);
int		index_normal(t_token *token, char **envp, int index);
void	parallel_start(t_token *token, char **envp, int i, int len);
void	start_fork(t_token *token, char **envp);
int		index_last(t_token *token, char **envp, int index);
int		open_outfile(t_token *token, int index);
char	*get_pathcmd(char *cmd, char **envp);
int		print_export(char **envp);
int		change_dir(t_token token, char **envp);
int		print_pwd(void);
void	parse_inre(t_token *token, int token_cnt);
void	parse_outre(t_token *token, int token_cnt);
int		parse_heredoc(t_token *token, int token_cnt);
void	parse_cmd(t_token *token, int token_cnt, char **envp);
int		is_quotes(t_token *token, char c, int i);
char	*read_more(char *early_s);
int		print_env(char **envp);
int		print_unset(t_token token, char **envp);
int		free_and_return(char *temp, char **path);
int		print_echo(t_token token);
int		print_exit(t_token token);
int		do_builtin(t_token *token, char **envp, int index);
int		make_full_path_return(t_token *token, int index, char **envp);
int		do_execve(t_token *token, int index, char **envp);
void	perror_exit(char *str);
char	**dollar_split(char *str, char c);
int		is_spacepipe(char *str);
void	wait_fork(void);
char	**envpcopy(char **envp);
int		free_all_envp(char **envp, int flag);
int		do_export(t_token token, char **envp, int flag);
void	free_all_token(t_token *token, int len, char *str);
void	free_double(t_token *token, int index);
void	free_here_doc(t_token *token, int index);
void	free_option(t_token *token, int index);
void	free_arr(t_token *token, int index);
void	free_outfile(t_token *token, int index);
void	free_infile(t_token *token, int index);
void	init_pipesplit(t_pipesplit *p);
void	join_arr(t_token *token, int j, int i, char **arr);
void	get_lenpos(t_token *token, t_lenpos *lp);
void	init_token(t_token *t, int token_cnt);
int		check_syntax(char *str);
void	interrupthandler(int a);
void	signal_heredoc(void);
void	signal_shell(void);
void	signal_default(void);
void	signal_ignore(void);
void	terminal_init(struct termios *term);
void	ctrl_d(void);
void	unlink_lastdoc(t_token *token, t_heredoc hd, int token_cnt);
int		any_heredoc(t_token *token, int j, int i);
void	wait_heredoc(t_heredoc *hd);
int		any_infile(t_token *token, int j, int i);
char	*strtrim_withd(char const *s1, char const *set);
int		is_special(char *str);
char	*join_lastdollar(char *str, char *en_rv);
void	delete_quotes(t_token *token, int j, int i);
int		envp_len(char **envp);
char	*get_home(char **envp);
int		is_exist(t_token *t, char *str, t_lenpos lp);
void	strjoin_withs(t_token *token, t_lenpos lp, char *str);
char	*get_jointemp(char **arr);
int		signal_execve(t_token *token, int index, char **envp);
void	wait_and_signal(void);
int		change_path(t_token *token, int index);
char	**splitnjoin(t_token *token, int j, char *sep);
char	**doubleq_split(char const *s, char c);
int		find_pipe(char *str, int *i, int *pos);
void	get_inquotes(char c, t_pipesplit *p);
void	get_cwinfo(char const *s, char c, t_pipesplit *p);
void	get_cnt(char const *s, char c, t_pipesplit *p, size_t *pos);
void	doubleq_parse(t_token *token, int j, int i, char **envp);
char	*get_enrv(char **envp, char *str);
int		return_home(char *home);
int		return_not_home(t_token token);
int		do_builtin_one(t_token *token, char **envp);
void	exe_builtin_one(t_token *token, int kind, char **envp);
int		is_undefined(char *str);
void	print_defined(char **envp, int i, int j, int flag);
void	print_arr(char **envp);

#endif
