/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:44:35 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/25 20:53:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lemin.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

int			hmap_index(const char *key)
{
	size_t		i;
	uint32_t	hash;

	hash = 0;
	i = -1;
	while (key[++i] != '\0')
		hash = 33 * (hash ^ key[i]);
	return (hash % HMAP_SIZE);
}

void			hmap_add(t_list *hmap, t_room *room)
{
	int			index;

	index = hmap_index(room->name);
	ft_list_push_front(&hmap[index], ft_list_link_new(room, sizeof(*room)));
}
