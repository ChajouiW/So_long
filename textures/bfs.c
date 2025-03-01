/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:44:17 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/28 21:11:17 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_on(t_game *game, char **copy, t_node **queue, t_node *current)
{
	int			i;
	int			nx;
	int			ny;
	t_direction	*dirs;

	i = 0;
	dirs = set_dirs();
	while (i < 4)
	{
		nx = current->x + dirs[i].x;
		ny = current->y + dirs[i].y;
		if (nx >= 0 && nx < game->cols && ny >= 0 && ny < game->rows)
		{
			if (copy[ny][nx] != '1' && copy[ny][nx] != 'v')
			{
				copy[ny][nx] = 'v';
				enqueue(queue, nx, ny);
			}
		}
		i++;
	}
	free(dirs);
}

int	bfs(t_game *game, char **copy)
{
	int		collected;
	int		exits;
	t_node	*queue;
	t_node	*current;

	queue = creat_node(game->player_x, game->player_y);
	copy[game->player_y][game->player_x] = 'v';
	(1) && (collected = 0, exits = 0);
	while (queue)
	{
		current = dequeue(&queue);
		if (game->map[current->y][current->x] == 'C')
			collected++;
		if (game->map[current->y][current->x] == 'E')
			exits = 1;
		move_on(game, copy, &queue, current);
		free(current);
	}
	ft_free(copy, 0);
	if (collected != game->collectibles || !exits)
		return (write(2, "Error\nInvalid map\n", 18), 0);
	return (1);
}
