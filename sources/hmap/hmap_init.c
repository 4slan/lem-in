/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 10:53:53 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/21 16:28:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		hmap_init(t_hmap *hmap)
{
	int		i;

	i = -1;
	while (++i < HMAP_SIZE)
	{
		hmap[i].room = NULL;
		hmap[i].next = NULL;
	}
}
