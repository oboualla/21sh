/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <oboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:44:33 by oboualla          #+#    #+#             */
/*   Updated: 2019/11/28 21:36:43 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 20
# include "../../libft/libft.h"

typedef struct		s_reste
{
	int				fd;
	char			*reste;
	struct s_reste	*next;
}					t_reste;

int					get_next_line(const int fd, char **line, char *sep);

#endif
