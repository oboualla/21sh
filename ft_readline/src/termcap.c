/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:05:02 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/25 14:19:56 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

int	init_tc(t_capab **tc)
{
	if (tgetent(NULL, getenv("TERM")) <= 0)
		return (-1);
	if (!(*tc = (t_capab*)ft_memalloc(sizeof(t_capab))))
		return (-1);
	if (!((*tc)->move_left = tgetstr("le", NULL)))
		return (-1);
	if (!((*tc)->move_right = tgetstr("nd", NULL)))
		return (-1);
	if (!((*tc)->move_up = tgetstr("up", NULL)))
		return (-1);
	if (!((*tc)->move_down = tgetstr("do", NULL)))
		return (-1);
	if (!((*tc)->show_curs = tgetstr("ve", NULL)))
		return (-1);
	if (!((*tc)->hide_curs = tgetstr("vi", NULL)))
		return (-1);
	if (!((*tc)->begin_curs = tgetstr("cr", NULL)))
		return (-1);
	if (!((*tc)->clear_line = tgetstr("ce", NULL)))
		return (-1);
	return (1);
}

int	init_mode(void)
{
	t_termios tr;

	if (tcgetattr(0, &tr) == -1)
		return (-1);
	tr.c_lflag &= ~(ICANON | ECHO);
	tr.c_cc[VMIN] = 1;
	tr.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &tr) == -1)
		return (-1);
	return (1);
}
