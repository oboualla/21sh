/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:56:23 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/08 17:52:11 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

void	hm(t_objet *obj)
{
	t_curpos	oldpos;
	t_curpos	newpos;

	if (obj->rd.curpos > 0)
	{
		oldpos = get_curpos(obj->line, obj->rd);
		obj->rd.curpos = 0;
		newpos = get_curpos(obj->line, obj->rd);
		curs_newpos(oldpos, newpos, obj->tc);
	}
}

void	ed(t_objet *obj)
{
	t_curpos	old_pos;
	t_curpos	new_pos;

	if (obj->rd.curpos < ft_strlen(obj->line))
	{
		old_pos = get_curpos(obj->line, obj->rd);
		obj->rd.curpos = ft_strlen(obj->line);
		new_pos = get_curpos(obj->line, obj->rd);
		curs_newpos(old_pos, new_pos, obj->tc);
	}
}

void	bs(t_objet *obj)
{
	size_t		i;
	t_curpos	old_pos;
	t_curpos	new_pos;

	if (obj->rd.curpos && ft_strlen(obj->line))
	{
		old_pos = get_curpos(obj->line, obj->rd);
		obj->rd.curpos--;
		new_pos = get_curpos(obj->line, obj->rd);
		i = obj->rd.curpos - 1;
		while (obj->line[++i])
			obj->line[i] = obj->line[i + 1];
		curs_newpos(old_pos, new_pos, obj->tc);
		ft_putstr(tgetstr("cd", NULL));
		if (obj->rd.curpos < ft_strlen(obj->line))
			bs_print(obj->line, obj->rd, obj->tc);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

int		other_key(t_objet *objet, unsigned int cast)
{
	if (cast == BS)
		bs(objet);
	else if (cast == HM)
		hm(objet);
	else if (cast == ED)
		ed(objet);
	else
		return (0);
	return (1);
}
