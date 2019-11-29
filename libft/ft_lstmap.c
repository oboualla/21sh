/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:16:58 by oboualla          #+#    #+#             */
/*   Updated: 2019/08/07 20:52:25 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *li;
	t_list *lili;

	if (!(lili = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(lst))
		return (NULL);
	lili = (*f)(lst);
	lst = lst->next;
	li = lili;
	if (lili)
	{
		while (lst)
		{
			li->next = (*f)(lst);
			lst = lst->next;
			li = li->next;
		}
		li->next = NULL;
		return (lili);
	}
	return (NULL);
}
