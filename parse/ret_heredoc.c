/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:18:15 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/04 22:43:16 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static char	*join_str(char *read, char *str)
{
	char	*join;
	char	*tmp;

	join = ft_strjoin(read, "\n");
	free(read);
	tmp = ft_strjoin(str, join);
	free(join);
	free(str);
	return (tmp);
}

char		*ret_heredoc(char *name)
{
	char	*str;
	char	*read;

	str = ft_strnew(0);
	save_line(&str);
	while ((read = ft_readline("heredoc")))
	{
		if (!str)
		{
			*save_line(NULL) = NULL;
			save_line(&read);
			return (NULL);
		}
		if (!read || !ft_strcmp(read, name))
		{
			ft_strdel(&read);
			break ;
		}
		str = join_str(read, str);
	}
	*save_line(NULL) = NULL;
	return (str);
}
