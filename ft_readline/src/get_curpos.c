/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:23:52 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/08 20:50:18 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

t_curpos	get_curpos(char *line, t_readl rd)
{
	t_curpos	cp;
	size_t		n;

	n = 0;
	cp.x = rd.prompt_len + 1;
	cp.y = 1;
	while (line[n] && n < rd.curpos)
	{
		if (line[n] == '\n' || cp.x == rd.ws_col)
		{
			cp.x = 1;
			cp.y++;
			n++;
			continue ;
		}
		cp.x++;
		n++;
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
