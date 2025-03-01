/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:41:09 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/25 16:37:29 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_exit(t_game *game, int x, int y, char dir)
{
	if (dir == 'u' && game->map[y + 1][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit[0],
			x * IMG_W, (y + 1) * IMG_H);
	else if (dir == 'd' && game->map[y - 1][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit[0],
			x * IMG_W, (y - 1) * IMG_H);
	else if (dir == 'l' && game->map[y][x + 1] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit[0],
			(x + 1) * IMG_W, y * IMG_H);
	else if (dir == 'r' && game->map[y][x - 1] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit[0],
			(x - 1) * IMG_W, y * IMG_H);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	move(t_game *game, int x, int y)
{
	char	dir;

	dir = game->dir;
	mlx_put_image_to_window(game->mlx, game->win, game->img_ptr,
		x * IMG_W, y * IMG_H);
	if (dir == 'u' && game->map[y + 1][x] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->floor,
			x * IMG_W, (y + 1) * IMG_H);
	else if (dir == 'd' && game->map[y - 1][x] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->floor,
			x * IMG_W, (y - 1) * IMG_H);
	else if (dir == 'l' && game->map[y][x + 1] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->floor,
			(x + 1) * IMG_W, y * IMG_H);
	else if (dir == 'r' && game->map[y][x - 1] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->floor,
			(x - 1) * IMG_W, y * IMG_H);
	else
		handle_exit(game, x, y, dir);
	if (game->moves != game->last_count)
	{
		game->last_count = game->moves;
		ft_putnbr(game->moves);
		write(1, "\n", 1);
	}
}

void	render_map(t_game *game, int x, int y)
{
	while (y < game->rows * IMG_H)
	{
		while (x < game->cols * IMG_W)
		{
			if (game->map[y / IMG_W][x / IMG_H] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->floor, x, y);
			if (game->map[y / IMG_W][x / IMG_W] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->wall, x, y);
			else if (game->map[y / IMG_W][x / IMG_W] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_ptr, x, y);
			else if (game->map[y / IMG_W][x / IMG_W] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->collectible, x, y);
			else if (game->map[y / IMG_W][x / IMG_W] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->exit[0], x, y);
			x += IMG_W;
		}
		(1) && (y += IMG_H, x = 0);
	}
}

void	gaming(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->cols * IMG_W,
			game->rows * IMG_H, "so_long");
	ft_init(game);
	render_map(game, 0, 0);
	mlx_hook(game->win, 2, 1L << 0, f, game);
	mlx_hook(game->win, 17, 1L << 17, exit_cleanly, game);
	mlx_loop(game->mlx);
}
