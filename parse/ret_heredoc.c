/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:18:15 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/09 19:49:01 by oboualla         ###   ########.fr       */
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

char		*save_cmd(char *ncmd)
{
	static char *save = NULL;

	if (ncmd)
		save = ncmd;
	return (save);
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
			save_cmd(read);
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
