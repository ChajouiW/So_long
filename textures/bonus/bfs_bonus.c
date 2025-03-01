/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:44:17 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/24 19:49:47 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			if (copy[ny][nx] != '1' && copy[ny][nx] != 'v'
				&& copy[ny][nx] != 'G')
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
		return (0);
	return (1);
}
// void	lost(t_game *game, int x, int y)
// {
// 	int (w), h;
// 	static int	i;
// 	void	*img;
// 	long	delay;

// 	delay = 0;
// 	w = game->end[i]->w;
// 	h = game->end[i]->h;
// 	img = game->end[i]->img;
// 	i++;
// 	x = game->cols * IMG_W;
// 	x /= 2;
// 	x = x - (w / 2);
// 	y = game->rows * IMG_W;
// 	y /= 2;
// 	y = y - (h / 2);
// 	while (delay++ < 50000)
// 		mlx_put_image_to_window(game->mlx, game->win, img, x, y);
// }