/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:56:39 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/23 19:02:41 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int			i;
	t_direction	*dirs;

	i = 0;
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
