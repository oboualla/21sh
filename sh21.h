/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:51:12 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 19:48:45 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H
# include "libft/libft.h"
# include "ft_readline/includes/read_line.h"
# include "parse/parse.h"
# include <sys/types.h>
# include <sys/wait.h>
# define SETENV 2
# define UNSETENV 4
# define BGREEN "\033[1;32m"
# define BBLUE "\033[1;36m\033[4;36m"

char			*save_cmd(char *ncmd);
void			ctrl_c(char **line);
t_vars			*get_lstvars(t_vars **lst);
char			*prompt(void);
int				modifier_line(t_vars *lst, char **line);
int				replace_var(t_vars *lst, char **line, size_t i);
int				replace_home(char **line, size_t i);
char			*ft_getenv(t_vars *lst, char *nom);
char			**make_param(char *cmd);
int				quots(char **line);
int				check_pipe(char **line);
char			**make_env(t_vars *tmp);
t_vars			*ft_vars(char **env);
char			*access_file(char **env, char *file);
void			free_paths(char **paths);
void			do_cd(char **args, char **env, t_vars **vars);
void			ft_echo(char **args);
void			ft_setenv(char **args, t_vars **vars);
void			ft_unsetenv(char **args, t_vars **vars);
void			free_sh(char **env, char **args, t_vars **vars);
void			free_list(t_vars **vars);
void			ft_freeall(char **line, char **read, t_parse *prs);
void			show_env(char **env);
size_t			get_next_index(const char *cmd, size_t index);
#endif
