/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:42:49 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/27 16:09:18 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static int		finchr(char *str, int i)
{
	char	flag;

	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			flag = str[i++];
			while (str[i] != flag)
				i++;
		}
		if (str[i] == '|' || str[i] == ';')
			return (i + 1);
		i++;
	}
	return (i);
}

static char		*get_cmd(char *str, int *i)
{
	int		fin;
	char	*cmd;
	char	*fcmd;

	fin = finchr(str, *i);
	fcmd = ft_strsub(str, *i, fin);
	cmd = ft_strtrim(fcmd);
	*i = fin;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	free(fcmd);
	return (cmd);
}

static char		get_link(char *str)
{
	char	c;

	c = str[ft_strlen(str) - 1];
	if (ft_strlen(str) <= 1 && (c == ';' || c == '|'))
	{
		ft_putstr_fd("sh: parse error near '", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("'\n", 2);
		return ('e');
	}
	if (c == '|')
	{
		str[ft_strlen(str) - 1] = '\0';
		return ('p');
	}
	else if (c == ';')
	{
		str[ft_strlen(str) - 1] = '\0';
		return ('v');
	}
	return ('n');
}

static t_parse	*new_parse(char *str, int *i)
{
	t_parse	*parse;

	parse = (t_parse*)malloc(sizeof(t_parse));
	parse->next = NULL;
	parse->red = NULL;
	parse->cmd = get_cmd(str, i);
	if ((parse->link = get_link(parse->cmd)) == 'e')
	{
		ft_freeall(NULL, NULL, parse);
		return (NULL);
	}
	if (make_red(&parse->cmd, &parse->red) < 0)
	{
		if (save_line(NULL) && *save_line(NULL))
		{
			str = **save_line(NULL);
			*save_line(NULL) = NULL;
			ctrl_c(&str);
			return (parse_line(str));
		}
		ft_freeall(NULL, NULL, parse);
		return (NULL);
	}
	return (parse);
}

t_parse			*parse_line(char *str)
{
	t_parse		*parse;
	t_parse		*head;
	int			i;

	if (!str)
		return (NULL);
	i = 0;
	if (!(parse = new_parse(str, &i)))
		return (NULL);
	head = parse;
	while (str[i])
	{
		if (!(parse->next = new_parse(str, &i)))
		{
			ft_freeall(NULL, NULL, head);
			return (NULL);
		}
		parse = parse->next;
	}
	return (head);
}
