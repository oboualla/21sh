/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:53:13 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 16:06:40 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static size_t	get_sizeparm(const char *cmd)
{
	size_t size;
	size_t parm;

	parm = 1;
	size = 0;
	while (cmd[size])
	{
		if ((cmd[size] == '"' || cmd[size] == '\'') && cmd[size - 1] != '\\')
			size = get_next_index(cmd, size);
		if (size > 0 && cmd[size] == ' '
		&& cmd[size - 1] != '\\' && cmd[size - 1] != ' ')
			parm++;
		size++;
	}
	return (parm);
}

static int		check_chr(char *src, size_t *j, size_t *balance)
{
	if (src[*j] == '\\')
		(*j)++;
	if (src[*j] == '"' && (!*j || src[(*j) - 1] != '\\')
	&& !((*balance) & 2))
	{
		*balance = ((*balance) > 0) ? 0 : 1;
		if (!*balance && src[(*j) + 1] == ' ')
			return (0);
		(*j)++;
	}
	else if (src[*j] == '\'' && (!*j ||
	src[(*j) - 1] != '\\') && !((*balance) & 1))
	{
		*balance = ((*balance) > 0) ? 0 : 2;
		if (!(*balance) && src[(*j) + 1] == ' ')
			return (0);
		(*j)++;
	}
	return (1);
}

static void		ft_strncpy_arg(char *dest, char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t balance;

	balance = 0;
	j = 0;
	i = 0;
	while (j < n)
	{
		if (!(check_chr(src, &j, &balance)))
			break ;
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

static void		cpy_arg(char *cmd, size_t *index, char **argum)
{
	size_t start;
	ushort balance;

	start = *index;
	start += (size_t)ft_skip_sep(&cmd[*index], " \n\t");
	*index = start;
	balance = 0;
	while (cmd[start])
	{
		if (cmd[start] == ' ' && cmd[start - 1] != '\\')
			break ;
		if ((cmd[start] == '"' || cmd[start] == '\'') && cmd[start - 1] != '\\')
		{
			start = get_next_index(cmd, start);
			balance += 1;
		}
		start++;
	}
	if (!(*argum = (char*)
	ft_memalloc(sizeof(char) * ((start - balance) - (*index) + 1))))
		return ;
	ft_strncpy_arg(*argum, &cmd[*index], start - (*index));
	while (cmd[start] && cmd[start] == ' ')
		start++;
	*index = start;
}

char			**make_param(char *cmd)
{
	char	**argv;
	size_t	i;
	size_t	j;

	if (!cmd)
		return (NULL);
	j = 0;
	i = 0;
	j = get_sizeparm(cmd);
	if (!(argv = (char**)ft_memalloc(sizeof(char*) * (j + 1))))
		return (NULL);
	j = 0;
	while (cmd[i])
		cpy_arg(cmd, &i, &argv[j++]);
	argv[j] = NULL;
	return (argv);
}
