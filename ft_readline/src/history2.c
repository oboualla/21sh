/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:48:47 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 21:31:30 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static int	free_alloc_firstcmd(t_hist **lst, char *line, t_ushort func)
{
	if (func == 1)
	{
		if ((*lst)->back && (*lst)->next)
			*lst = (*lst)->next;
		else if (!(*lst)->back)
		{
			(*lst)->back = make_node(ft_strdup(line));
			(*lst)->back->next = (*lst);
		}
		else
		{
			ft_putstr(tgetstr("bl", NULL));
			return (0);
		}
	}
	else if (!(*lst)->back)
	{
		(*lst) = (*lst)->next;
		ft_strdel(&(*lst)->back->line);
		ft_memdel((void**)&(*lst)->back);
	}
	return (1);
}

void		kp(t_hist **lst, t_objet *obj)
{
	t_curpos	curpos;
	t_curpos	newpos;

	if ((*lst))
	{
		if (!(free_alloc_firstcmd(lst, obj->line, 1)))
			return ;
		ft_bzero((void*)obj->line, 1024);
		ft_strcpy(obj->line, (*lst)->line);
		curpos = get_curpos(obj->rd);
		obj->rd.curpos = 0;
		newpos = get_curpos(obj->rd);
		curs_newpos(curpos, newpos, obj->tc);
		ft_putstr(tgetstr("cd", NULL));
		if (obj->line[0] != '\0')
		{
			reprint(obj->line, obj->rd, obj->tc);
			obj->rd.curpos++;
			ed(obj);
		}
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

void		kd(t_hist **lst, t_objet *obj)
{
	t_curpos curpos;
	t_curpos newpos;

	if ((*lst) && (*lst)->back)
	{
		*lst = (*lst)->back;
		ft_bzero((void*)obj->line, 1024);
		ft_strcpy(obj->line, (*lst)->line);
		curpos = get_curpos(obj->rd);
		obj->rd.curpos = 0;
		newpos = get_curpos(obj->rd);
		curs_newpos(curpos, newpos, obj->tc);
		ft_putstr(tgetstr("cd", NULL));
		if (obj->line[0] != '\0')
		{
			reprint(obj->line, obj->rd, obj->tc);
			obj->rd.curpos++;
			ed(obj);
		}
		free_alloc_firstcmd(lst, obj->line, 2);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}
