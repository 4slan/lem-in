/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:30:46 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/16 22:07:45 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "parsing.h"

#include "algo.h"
#include "tools.h"

#include <stdlib.h>

t_farm	g_farm;

int		lemin(int ac, char **av)
{
	t_list	hmap[HMAP_SIZE];

	hmap_init(hmap);
	if (parse_input(hmap) == FAILURE)
		exit(EXIT_FAILURE);
	/* dbg_farm_print(&g_farm); */
	remove_deadend();
	resolve();
	return (SUCCESS);
}
