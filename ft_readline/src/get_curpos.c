/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:23:52 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/14 17:46:17 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

t_curpos	get_curpos(t_readl rd)
{
	t_curpos	cp;

	cp.x = (rd.curpos + 1) + rd.prompt_len;
	cp.y = 1;
	while (cp.x > rd.ws_col)
	{
		cp.x -= (size_t)rd.ws_col;
		cp.y++;
	}
	return (cp);
}

void		curs_newpos(t_curpos curpos, t_curpos newpos, t_capab *tc)
{
	ft_putstr(tc->hide_curs);
	if (curpos.y > newpos.y)
	{
		while (--curpos.y >= newpos.y)
			to_up_line(tc);
	}
	else
	{
		while (++curpos.y <= newpos.y)
			to_next_line(tc, 1);
	}
	ft_putstr(tc->begin_curs);
	curpos.x = 1;
	while (++curpos.x <= newpos.x)
		ft_putstr(tc->move_right);
	ft_putstr(tc->show_curs);
}
