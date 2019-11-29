/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:23:29 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 14:25:05 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

void	move_curs(t_readl *rd, t_capab *tc, size_t bufsize)
{
	t_curpos oldpos;
	t_curpos newpos;

	oldpos = get_curpos(*rd);
	rd->curpos += (bufsize - 1);
	newpos = get_curpos(*rd);
	curs_newpos(oldpos, newpos, tc);
}

void	l_print(char *line, t_readl *rd, t_capab *tc, size_t bufsize)
{
	t_curpos cp;

	if ((rd->curpos + 1) == ft_strlen(line))
	{
		cp = get_curpos(*rd);
		ft_putchar(line[(*rd).curpos]);
		if (cp.x == rd->ws_col)
			to_next_line(tc, 0);
	}
	else
		reprint(line, *rd, tc);
	rd->curpos++;
	if (bufsize > 1)
		move_curs(rd, tc, bufsize);
}

void	bs_print(char *line, t_readl rd, t_capab *tc)
{
	t_curpos	cur_pos;
	t_curpos	oldpos;
	size_t		i;

	i = rd.curpos;
	cur_pos = get_curpos(rd);
	oldpos = cur_pos;
	ft_putstr(tc->hide_curs);
	ft_putstr(tc->clear_line);
	while (line[i])
	{
		while (line[i] && (cur_pos.x < (rd.ws_col + 1)))
		{
			ft_putchar(line[i++]);
			cur_pos.x++;
		}
		if (cur_pos.x == (rd.ws_col + 1))
		{
			cur_pos.x = 1;
			cur_pos.y++;
			to_next_line(tc, 0);
		}
	}
	curs_newpos(cur_pos, oldpos, tc);
	ft_putstr(tc->show_curs);
}

void	reprint(char *line, t_readl rd, t_capab *tc)
{
	t_curpos	old_pos;

	old_pos = get_curpos(rd);
	bs_print(line, rd, tc);
	if (old_pos.x != rd.ws_col)
		ft_putstr(tc->move_right);
	else
		to_next_line(tc, 1);
	ft_putstr(tc->show_curs);
}
