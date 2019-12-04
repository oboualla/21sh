/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:23:52 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/04 02:21:15 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

t_curpos	get_curpos1(t_readl rd)
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

size_t		chr_index(char *str, size_t n,  char c)
{
	if (n)
		n--;
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
	t_curpos	line_pos;
	size_t		index;

	index = 1;
	cp.y = 1;
	if (!ft_strchr(line, '\n'))
		return (get_curpos1(rd));
	index += chr_index(line, rd.curpos, '\n');
	cp.y += chr_calc(line, rd.curpos, '\n');
//	line_pos = get_cutpos1((t_readl){rd.ws_col, rd.ws_row, 0, rd.curpos});
	if (rd.curpos >= index && cp.y != 1)
		cp.x = (rd.curpos - index) + 1;
	else
		cp.x = (rd.curpos) + 1;
	if (cp.y == 1)
		cp.x += rd.prompt_len;
	line_pos = get_curpos1((t_readl){rd.ws_col, rd.ws_row, 0, cp.x - 1});
	if (line_pos.y > 1)
	{
		cp.x = line_pos.x;
		cp.y += (line_pos.y - 1);
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
