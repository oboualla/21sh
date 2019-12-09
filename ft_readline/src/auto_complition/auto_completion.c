/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:29:41 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/08 22:38:41 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libac.h"

static size_t	begin_ac(t_objet *obj)
{
	size_t i;

	i = obj->rd.curpos;
	while (i > 0 && obj->line[i - 1] != ' ')
	{
		kl(obj);
		i--;
	}
	return (i);
}

static int		get_fp(t_ac *ac, t_objet *obj)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = begin_ac(obj);
	if (obj->line[i] != ' ')
	{
		ac->file = ft_strcdup(obj->line + i, ' ');
		if ((ptr = ft_strrchr(ac->file, '/')))
		{
			ac->path = ac->file;
			ac->file = ft_strdup(ptr + 1);
			len = (ft_strlen(ac->path) - ft_strlen(ac->file));
			ft_memset((void*)&ac->path[len], '\0', ft_strlen(ac->file));
			modifier_line(get_lstvars(NULL), &ac->path);
			return (1);
		}
	}
	ac->path = ft_strdup(".");
	return (1);
}

static char		*get_cmd(char *line)
{
	char	*ptr;
	char	cmd[100];
	size_t	i;
	size_t	j;

	if (!(ptr = ft_strrchr(line, ';')))
		ptr = line;
	else
		(*ptr)++;
	j = 0;
	i = ft_skip_sep(ptr, " ");
	while (ptr[i] && ptr[i] != ' ')
		cmd[j++] = line[i++];
	if (j == 0)
		return (NULL);
	cmd[j] = '\0';
	return (ft_strdup(cmd));
}

static void		reset_curs(t_objet *obj)
{
	char *line;

	line = obj->line;
	while (line[obj->rd.curpos])
	{
		if (line[obj->rd.curpos] == ' ' && line[obj->rd.curpos - 1] != '\\')
			break ;
		kr(obj);
	}
}

int				auto_c(t_objet *obj)
{
	t_ac	*ac;
	size_t	len;
	size_t	cmp;

	len = 0;
	if (!(ac = (t_ac*)ft_memalloc(sizeof(t_ac))))
		return (-1);
	if (!(ac->cmd = get_cmd(obj->line)))
		return (exit_prog(&ac));
	get_fp(ac, obj);
	if (!(get_lfile(ac, &len)))
	{
		reset_curs(obj);
		return (exit_prog(&ac));
	}
	cmp = get_len(ac->files);
	if (cmp == ft_strlen(ac->file))
	{
		print_ac(ac, obj, len);
		reset_curs(obj);
	}
	else
		complet_line(ac, obj, cmp);
	return (exit_prog(&ac));
}
