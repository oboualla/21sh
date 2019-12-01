/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:23:52 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/02 00:11:50 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

t_curpos	get_curpos(char *line, t_readl rd)
{
	t_curpos	cp;

	(void)line;
	cp.x = (rd.curpos + 1) + rd.prompt_len;
	cp.y = 1;
	while (cp.x > rd.ws_col)
	{
		cp.x -= (size_t)rd.ws_col;
		cp.y++;
	}
	return (cp);
}
/*
size_t		chr_index(char *str, size_t n,  char c)
{
	while (n > 0 && str[n] != c)
		n--;
	return (n);
}

size_t		chr_calc(char *str, size_t n, char c)
{
	size_t i = 0;
	size_t cal = 0;

	while (str[i] && i < n)
	{
		if (str[i] == c)
			cal++;
		i++;
	}
	return (cal);
}

t_curpos	get_curpos(char *line, t_readl rd)
{
	t_curpos	cp;
	size_t		index;

	index = 1;
	cp.y = 1;
	if (!ft_strchr(line, '\n'))
		return (get_curpos1(rd));
	index += chr_index(line, rd.curpos, '\n');
	cp.y += chr_calc(line, rd.curpos, '\n');
	cp.x = (rd.curpos - index) + 1;
	return (cp); 
}
*/
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
