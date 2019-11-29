/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libac.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 00:35:26 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 21:27:19 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBAC_H
# define LIBAC_H
# include "read_line.h"
# define ONLY_DIR    1
# define ONLY_CMD    2
# define ALL         3

typedef struct s_ac		t_ac;
typedef struct s_vars	t_vars;

struct	s_vars
{
	char			*nom;
	char			*valeur;
	struct s_vars	*next;
};

struct	s_ac
{
	char	*cmd;
	char	*file;
	char	*path;
	char	**files;
};

int		modifier_line(t_vars *lst, char **line);
t_vars	*get_lstvars(t_vars **lst);
int		ft_strcmp_index(char *file, char *cmp);
size_t	get_len(char **t_file);
int		exit_prog(t_ac **ac);
char	*get_file(char *file, char *path, size_t *len, ushort mode);
int		get_lfile(t_ac *ac, size_t *len);
void	couleur(char *file, char *path);
int		print_ac(t_ac *ac, t_objet *obj, size_t len);
void	complet_line(t_ac *ac, t_objet *obj, size_t cmp);
#endif
