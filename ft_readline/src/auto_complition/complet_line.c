/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complet_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 01:27:45 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 14:30:09 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libac.h"

static char	*get_change(char *line, t_ac *ac)
{
	size_t	i;
	char	*change;
	char	*tmp;

	i = 0;
	if (ft_strcmp(ac->path, "."))
		change = ft_strjoin(ac->path, ac->files[0]);
	else
		change = ft_strdup(ac->files[0]);
	while (line[i] && line[i] != ' ')
		i++;
	tmp = ft_strjoin(change, &line[i]);
	free(change);
	return (tmp);
}

static void	stock_ac(t_ac *ac, char line[], t_readl rd)
{
	char	*change;
	char	*tmp;
	size_t	len;

	len = 0;
	if (!ac->file || !ac->file[0])
		change = get_change(&line[rd.curpos], ac);
	else
	{
		if (ft_strcmp(ac->path, "."))
			len = ft_strlen(ac->path);
		change = ft_remplacer_str(&line[rd.curpos + len],
		ac->file, ac->files[0]);
		if (ft_strcmp(ac->path, "."))
		{
			tmp = change;
			change = ft_strjoin(ac->path, change);
			free(tmp);
		}
	}
	ft_bzero((void*)&line[rd.curpos], ft_strlen(line) - rd.curpos);
	ft_strcat(line, change);
	ft_strdel(&change);
}

void		complet_line(t_ac *ac, t_objet *obj, size_t cmp)
{
	char		*line;
	t_readl		*rd;

	line = obj->line;
	ft_bzero((void*)&ac->files[0][cmp], ft_strlen(ac->files[0]) - cmp);
	stock_ac(ac, line, obj->rd);
	reprint(line, obj->rd, obj->tc);
	rd = &obj->rd;
	while (line[rd->curpos])
	{
		if (line[rd->curpos] == ' ' && line[rd->curpos - 1] != '\\')
			break ;
		kr(obj);
	}
}
