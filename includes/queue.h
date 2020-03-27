/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 10:41:12 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/27 12:54:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# define SUCCESS 0
# define FAILURE 1

typedef struct	s_queue t_queue;

struct			s_queue
{
	ssize_t		front;
	ssize_t		rear;
	ssize_t		size;
	size_t		capacity;
	int			*array;
};

t_queue		*queue_create(unsigned capacity);

int			queue_isfull(t_queue *queue);
int			queue_isempty(t_queue *queue);

/*
** QUEUE_H
*/
#endif