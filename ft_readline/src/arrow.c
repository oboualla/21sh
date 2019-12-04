/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:23:37 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/03 18:13:35 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

void	to_next_line(t_capab *tc, t_ushort flag)
{
	ft_putstr(tc->move_down);
	ft_putstr(tc->begin_curs);
	if (flag != 1)
		ft_putstr(tc->clear_line);
}

void	to_up_line(t_capab *tc)
{
	ft_putstr(tc->move_up);
	ft_putstr(tc->begin_curs);
}

void	kl(t_objet *obj)
{
	t_curpos	curpos;
	t_curpos	newpos;

	if (obj->rd.curpos > 0)
	{
		curpos = get_curpos(obj->line, obj->rd);
		obj->rd.curpos--;
		newpos = get_curpos(obj->line, obj->rd);
		curs_newpos(curpos, newpos, obj->tc);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

void	kr(t_objet *obj)
{
	t_curpos curpos;
	t_curpos newpos;

	if (obj->rd.curpos < ft_strlen(obj->line))
	{
		curpos = get_curpos(obj->line, obj->rd);
		obj->rd.curpos++;
		newpos = get_curpos(obj->line, obj->rd);
		curs_newpos(curpos, newpos, obj->tc);
	}
	else
		ft_putstr(tgetstr("bl", NULL));
}

int		arrow_key(t_objet *objet, t_hist **lst, unsigned int cast)
{
	if (cast == KL)
		kl(objet);
	else if (cast == KR)
		kr(objet);
	else if (cast == KP)
		kp(lst, objet);
	else if (cast == KD)
		kd(lst, objet);
	else
		return (0);
	return (1);
}
