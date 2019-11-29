/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:40:38 by kbahrar           #+#    #+#             */
/*   Updated: 2019/11/25 14:56:26 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static int	size_var(t_vars *vars)
{
	int	tot;

	tot = 0;
	while (vars)
	{
		vars = vars->next;
		tot++;
	}
	return (tot);
}

char		**make_env(t_vars *tmp)
{
	char	**env;
	char	*ptr;
	int		i;

	if (!tmp)
		return (NULL);
	if (!(env = (char**)ft_memalloc(sizeof(char*) * (size_var(tmp) + 1))))
		return (NULL);
	i = 0;
	while (tmp)
	{
		env[i] = ft_strjoin(tmp->nom, "=");
		ptr = env[i];
		env[i] = ft_strjoin(ptr, tmp->valeur);
		free(ptr);
		tmp = tmp->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}
