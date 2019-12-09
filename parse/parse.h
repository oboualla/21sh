/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:37:32 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/08 22:45:10 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_vars
{
	char				*nom;
	char				*valeur;
	struct s_vars		*next;
}						t_vars;

typedef struct			s_redirec
{
	char				*file;
	int					ffd;
	int					fd;
	char				link;
	struct s_redirec	*next;
	char				*heredoc;
}						t_redirec;

typedef struct			s_parse
{
	char				*cmd;
	struct s_parse		*next;
	t_redirec			*red;
	char				link;
}						t_parse;

int						check_child(int status);
void					ctrl_c(char **line);
char					***save_line(char **line);
t_parse					*parse_line(char *line);
int						make_red(char **cmd, t_redirec **redi);
void					exec(t_parse *prs, t_vars **vars);
char					*ft_herdoc(t_redirec *red);
int						ft_redirec(t_redirec *red);
int						ft_pipehelp(t_parse *prs);
int						ft_pipe(int flag);
void					ft_retfd(int flag);
char					*ret_heredoc(char *name);
char					*ret_file(char *str, int *i);
int						ret_fd(char *str, int *i);
char					ret_link(char *str, int *i);
int						ret_ffd(char *str, int i);
#endif
