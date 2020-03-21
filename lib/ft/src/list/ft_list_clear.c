/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:19:41 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/01 14:20:32 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list *list, void (*del)(void *, size_t))
{
	t_list_link	*link;
	t_list_link	*next;

	link = list->head;
	next = link->next;
	while (next != list->head)
	{
		ft_list_delone(list, link, del);
		link = next;
		next = link->next;
	}
	ft_list_delone(list, link, del);
	list->head = NULL;
}