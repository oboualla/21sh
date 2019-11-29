/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:46:29 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/19 14:00:23 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p;

	if (!(p = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (p)
		{
			p->content = malloc(sizeof(content) * (content_size + 1));
			p->content = ft_memcpy(p->content, content, content_size);
			p->content_size = content_size;
			p->next = NULL;
		}
	}
	else
	{
		p->content = NULL;
		p->content_size = 0;
		p->next = NULL;
	}
	return (p);
}
