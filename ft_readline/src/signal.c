/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:41:31 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 19:42:54 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

static void	reprint_prompt(t_objet *obj)
{
	if (!obj)
		return ;
	if (!ft_strcmp(obj->prompt, "dquote") ||
	!ft_strcmp(obj->prompt, "heredoc") || !ft_strcmp(obj->prompt, "pipe"))
	{
		ft_strdel(*save_line(NULL));
		obj->prompt = *save_prompt(NULL);
	}
	ed(obj);
	ft_putchar('\n');
	ft_putstr(tgetstr("cd", NULL));
	ft_putendl(obj->prompt);
	ft_putstr("$> ");
	ft_bzero((void*)obj->line, LINE_SIZE);
	obj->rd.curpos = 0;
}

static void	reset_curs(char *line, t_readl rd, t_capab *tc)
{
	t_curpos curpos;

	curpos = get_curpos(line, rd);
	rd.curpos = 0;
	ft_putstr(tc->hide_curs);
	while (--curpos.y)
		to_up_line(tc);
	to_up_line(tc);
	ft_putstr(tc->show_curs);
	ft_putstr(tgetstr("cd", NULL));
	sleep(1);
}

static void	reprint_line(t_objet *obj)
{
	t_winsize	ws;
	t_curpos	oldpos;
	t_curpos	curpos;
	size_t		index;

	if (!obj)
		return ;
	reset_curs(obj->line, obj->rd, obj->tc);
	index = obj->rd.curpos;
	obj->rd.curpos = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	obj->rd.ws_col = ws.ws_col;
	obj->rd.ws_row = ws.ws_row;
	ft_putendl(obj->prompt);
	ft_putstr("$> ");
	bs_print(obj->line, obj->rd, obj->tc);
	curpos = get_curpos(obj->line, obj->rd);
	obj->rd.curpos = index;
	oldpos = get_curpos(obj->line, obj->rd);
	curs_newpos(curpos, oldpos, obj->tc);
}

static void	sig1(int sig)
{
	(void)sig;
	if (sig == SIGINT)
		reprint_prompt(*save_objet(NULL));
	else if (sig == SIGWINCH)
		reprint_line(*save_objet(NULL));
}

void		init_sig(void)
{
	signal(SIGINT, sig1);
	signal(SIGWINCH, sig1);
}
