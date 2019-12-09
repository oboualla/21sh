/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:23:29 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 14:06:09 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static void	move_curs(char *line, t_readl *rd, t_capab *tc, size_t bufsize)
{
	t_curpos oldpos;
	t_curpos newpos;

	oldpos = get_curpos(line, *rd);
	rd->curpos += (bufsize - 1);
	newpos = get_curpos(line, *rd);
	curs_newpos(oldpos, newpos, tc);
}

void		l_print(char *line, t_readl *rd, t_capab *tc, size_t bufsize)
{
	t_curpos cp;

	(void)bufsize;
	if ((rd->curpos + 1) == ft_strlen(line))
	{
		cp = get_curpos(line, *rd);
		ft_putchar(line[(*rd).curpos]);
		if (cp.x == rd->ws_col)
			to_next_line(tc, 0);
	}
	else
		reprint(line, *rd, tc);
	rd->curpos++;
	if (bufsize > 1)
		move_curs(line, rd, tc, bufsize);
}

int			new_line(char c, t_curpos *curpos, t_readl rd, t_capab *tc)
{
	if (curpos->x == (rd.ws_col + 1) || c == '\n')
	{
		if (curpos->x == (rd.ws_col + 1) && c == '\n')
			to_next_line(tc, 0);
		curpos->x = 1;
		curpos->y++;
		to_next_line(tc, 0);
		if (c == '\n')
			return (1);
	}
	return (0);
}

void		bs_print(char *line, t_readl rd, t_capab *tc)
{
	t_curpos	cur_pos;
	t_curpos	oldpos;
	size_t		i;

	i = rd.curpos;
	cur_pos = get_curpos(line, rd);
	oldpos = cur_pos;
	ft_putstr(tc->hide_curs);
	ft_putstr(tc->clear_line);
	while (line[i])
	{
		while (line[i] && (cur_pos.x < (rd.ws_col + 1)) && line[i] != '\n')
		{
			ft_putchar(line[i++]);
			cur_pos.x++;
		}
		if (new_line(line[i], &cur_pos, rd, tc))
			i++;
	}
	cur_pos = get_curpos(line,
		(t_readl){rd.ws_col, rd.ws_row, rd.prompt_len, i});
	curs_newpos(cur_pos, oldpos, tc);
	ft_putstr(tc->show_curs);
}

void		reprint(char *line, t_readl rd, t_capab *tc)
{
	t_curpos	newpos;
	t_curpos	curpos;

	ft_putstr(tc->hide_curs);
	curpos = get_curpos(line, rd);
	bs_print(line, rd, tc);
	rd.curpos++;
	newpos = get_curpos(line, rd);
	ft_putstr(tc->show_curs);
	curs_newpos(curpos, newpos, tc);
}
