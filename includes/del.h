/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:35:09 by abosch            #+#    #+#             */
/*   Updated: 2020/06/03 07:02:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEL_H
# define DEL_H

# include <stddef.h>
# include "lemin.h"
# include "libft.h"

void	del_link_list(void *content, size_t size);
void	del_link(void *content, size_t size);
void	final_free(t_farm *f, t_list *hmap);

#endif
