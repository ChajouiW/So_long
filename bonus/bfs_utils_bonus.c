/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:56:39 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/24 15:28:47 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_node	*creat_node(int x, int y)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

void	enqueue(t_node **q, int x, int y)
{
	t_node	*tail;

	if (!*q)
	{
		*q = creat_node(x, y);
		return ;
	}
	tail = *q;
	while (tail->next)
		tail = tail->next;
	tail->next = creat_node(x, y);
}

t_node	*dequeue(t_node **queue)
{
	t_node	*front;

	if (!*queue)
		return (NULL);
	front = *queue;
	*queue = (*queue)->next;
	front->next = NULL;
	return (front);
}

t_direction	*set_dirs(void)
{
	t_direction	*dirs;

	dirs = malloc(sizeof(t_direction) * 4);
	dirs[0].x = -1;
	dirs[0].y = 0;
	dirs[1].x = 1;
	dirs[1].y = 0;
	dirs[2].x = 0;
	dirs[2].y = -1;
	dirs[3].x = 0;
	dirs[3].y = 1;
	return (dirs);
}
