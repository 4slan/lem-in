/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 20:54:45 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 03:59:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#include "lib.h"
#include "debug.h"
#include "tools.h"

static void		get_room_names_index(char *line, char *room_name[2],
					unsigned *room_index)
{
	room_name[0] = ft_strtok(line, "-");
	room_name[1] = ft_strtok(NULL, "-");
	room_index[0] = hmap_index(room_name[0]);
	room_index[1] = hmap_index(room_name[1]);
}

static int		get_room_link(t_list *hmap, t_list_link *room_link[2],
					unsigned *room_index, char *room_name[2])
{
	room_link[0] = ft_list_find(&hmap[room_index[0]],
		room_name[0], room_namecmp);
	room_link[1] = ft_list_find(&hmap[room_index[1]],
		room_name[1], room_namecmp);
	if (!room_link[0] || !room_link[1])
		return (FAILURE);
	return (SUCCESS);
}

static void		set_room_links(t_list_link *room_link[2])
{
	t_room		*room1;
	t_room		*room2;

	room1 = room_link[0]->content;
	room2 = room_link[1]->content;
	if (ft_list_find(room1->lnk.lst, &(room2->index), room_indexcmp)
		&& ft_list_find(room2->lnk.lst, &(room1->index), room_indexcmp))
		return ;
	ft_list_push(room1->lnk.lst,
		ft_list_link_new(&room2->index, sizeof(unsigned)));
	ft_list_push(room2->lnk.lst,
		ft_list_link_new(&room1->index, sizeof(unsigned)));
}

static int		add_links(t_list *hmap, char *line)
{
	unsigned	room_index[2];
	char		*room_name[2];
	t_list_link	*room_link[2];

	if (!ft_strchr(line, '-') || !ft_strrchr(line, '-')[1]
		|| ft_strccnt(line, '-') != 1)
		return (FAILURE);
	if (contains_whitespace(line) == SUCCESS)
		ft_printerr(E_WSPACE);
	get_room_names_index(line, room_name, room_index);
	if (ft_strequ(room_name[0], room_name[1]))
		return (SUCCESS);
	if (get_room_link(hmap, room_link, room_index, room_name) == FAILURE)
		return (FAILURE);
	set_room_links(room_link);
	return (SUCCESS);
}

int				get_links(t_list *hmap, char *line)
{
	if (!line)
		return (FAILURE);
	if (line[0] != '#')
		if (add_links(hmap, line) == FAILURE)
		{
			ft_strdel(&line);
			return (SUCCESS);
		}
	ft_strdel(&line);
	while (readline(&line, 1))
	{
		if (line[0] == '#')
		{
			ft_strdel(&line);
			continue ;
		}
		if (add_links(hmap, line) == FAILURE)
		{
			ft_strdel(&line);
			return (SUCCESS);
		}
		ft_strdel(&line);
	}
	return (SUCCESS);
}
