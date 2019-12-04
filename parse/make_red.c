/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:06:31 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/04 22:43:42 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static int	check_red(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i++];
			while (str[i] != c)
				i++;
		}
		if (str[i] == '<' || str[i] == '>')
			return (i);
		i++;
	}
	return (-1);
}

static int	err_red(char *str, int err, t_redirec *red)
{
	t_redirec	*tmp;

	tmp = red;
	if (str)
		ft_putstr_fd(str, 2);
	while (tmp)
	{
		red = tmp;
		ft_strdel(&red->file);
		ft_strdel(&red->heredoc);
		tmp = tmp->next;
		free(red);
		red = NULL;
	}
	return (err);
}

static int	new_red(char **cmd, int i, t_redirec **red)
{
	int			j;

	j = i;
	(*red)->next = NULL;
	(*red)->file = NULL;
	(*red)->heredoc = NULL;
	(*red)->ffd = ret_ffd(*cmd, i);
	if (((*red)->link = ret_link(*cmd, &i)) == 'e')
		return (err_red("21sh: parse error\n", -1, *red));
	(*red)->fd = ret_fd(*cmd, &i);
	if ((*red)->fd == -1000 || (*red)->fd == -500)
	{
		if (!((*red)->file = ret_file(*cmd, &i)))
			return (err_red("21sh: parse error\n", -1, *red));
	}
	else
		(*red)->file = NULL;
	if ((*red)->link == 'H')
		if (!((*red)->heredoc = ret_heredoc((*red)->file)))
			return (err_red(NULL, -3, *red));
	if ((*red)->ffd != -1)
		j = j - 1;
	*cmd = ft_strsubdel(*cmd, j, i);
	return (1);
}

int			make_red(char **cmd, t_redirec **redi)
{
	t_redirec	*red;
	t_redirec	*head;
	int			i;

	if ((i = check_red(*cmd)) == -1)
		return (0);
	red = (t_redirec*)malloc(sizeof(t_redirec));
	if (*redi == NULL)
		head = red;
	else
	{
		head = *redi;
		while (head->next)
			head = head->next;
	}
	if ((i = new_red(cmd, i, &red)) < 0)
		return (err_red(NULL, i, NULL));
	if (*redi == NULL)
		*redi = head;
	else
		head->next = red;
	if (check_red(*cmd) != -1)
		if (make_red(cmd, redi) == -1)
			return (err_red(NULL, -1, NULL));
	return (1);
}
