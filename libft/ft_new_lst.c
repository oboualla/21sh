/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:14:58 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/18 18:23:42 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_new_lst(t_list *lst, char *str)
{
	t_list *list;

	list = (t_list*)malloc(sizeof(t_list));
	if (!(list))
		return (NULL);
	list->content = (char *)str;
	list->content_size = sizeof(str);
	list->next = lst;
	return (list);
}
