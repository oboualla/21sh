/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacer_mot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:55:26 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 15:00:05 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static void	alt_l(t_objet *obj)
{
	t_curpos	curpos;
	t_curpos	newpos;
	t_readl		*rd;

	if ((obj->rd.curpos != 0))
	{
		rd = &obj->rd;
		curpos = get_curpos(obj->line, *rd);
		rd->curpos--;
		while (rd->curpos > 0 && obj->line[rd->curpos] == ' ')
			rd->curpos--;
		while (rd->curpos > 0 && obj->line[rd->curpos - 1] != ' ')
			rd->curpos--;
		newpos = get_curpos(obj->line, *rd);
		curs_newpos(curpos, newpos, obj->tc);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

static void	alt_r(t_objet *obj)
{
	t_curpos	curpos;
	t_curpos	newpos;
	t_readl		*rd;

	rd = &obj->rd;
	if ((rd->curpos != ft_strlen(obj->line)))
	{
		curpos = get_curpos(obj->line, *rd);
		while (obj->line[rd->curpos] && obj->line[rd->curpos] != ' ')
			obj->rd.curpos++;
		while (obj->line[rd->curpos] && obj->line[rd->curpos] == ' ')
			obj->rd.curpos++;
		newpos = get_curpos(obj->line, *rd);
		curs_newpos(curpos, newpos, obj->tc);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

static void	alt_p(t_objet *obj)
{
	t_curpos	curpos;
	t_curpos	newpos;
	size_t		n;

	n = 0;
	curpos = get_curpos(obj->line, obj->rd);
	if (curpos.y > 1)
	{
		while (obj->rd.curpos && (n < (obj->rd.ws_col + 1)))
		{
			obj->rd.curpos--;
			n++;
			if (obj->line[obj->rd.curpos] == '\n')
				break ;
		}
		newpos = get_curpos(obj->line, obj->rd);
		curs_newpos(curpos, newpos, obj->tc);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

static void	alt_d(t_objet *obj)
{
	t_curpos	curpos;
	t_curpos	endpos;
	t_curpos	newpos;
	t_readl		rd;
	size_t		n;

	n = 0;
	rd = obj->rd;
	curpos = get_curpos(obj->line, obj->rd);
	rd.curpos = ft_strlen(obj->line);
	endpos = get_curpos(obj->line, rd);
	if (curpos.y < endpos.y)
	{
		while (obj->line[obj->rd.curpos] && (n < obj->rd.ws_col + 1))
		{
			obj->rd.curpos++;
			n++;
			if (obj->line[obj->rd.curpos] == '\n')
				break ;
		}
		newpos = get_curpos(obj->line, obj->rd);
		curs_newpos(curpos, newpos, obj->tc);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

int			alt_key(t_objet *objet, unsigned int cast)
{
	if (cast == ALT_L)
		alt_l(objet);
	else if (cast == ALT_R)
		alt_r(objet);
	else if (cast == ALT_P)
		alt_p(objet);
	else if (cast == ALT_D)
		alt_d(objet);
	else
		return (0);
	return (1);
}
