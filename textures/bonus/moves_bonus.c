/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:43:40 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/28 23:18:14 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_exit(t_game *game, char dir)
{
	if (game->inexit)
	{
		if (dir == 'u')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->exit[2], game->exit_x * IMG_W, game->exit_y * IMG_H);
		else if (dir == 'd')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->exit[1], game->exit_x * IMG_W, game->exit_y * IMG_H);
		else if (dir == 'r')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->exit[4], game->exit_x * IMG_W, game->exit_y * IMG_H);
		else if (dir == 'l')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->exit[3], game->exit_x * IMG_W, game->exit_y * IMG_H);
		return ;
	}
}

void	game_ends(t_game *game, int x, int y)
{
	long	delay;
	void	*img;

	int (w), h;
	delay = 0;
	put_str(game);
	(game->map[y][x] == 'G') && (w = 300, h = 168, img = game->img->lost);
	(game->map[y][x] == 'E') && (w = 480, h = 270, img = game->img->win);
	x = game->cols * IMG_W;
	x /= 2;
	x = x - (w / 2);
	y = game->rows * IMG_W;
	y /= 2;
	y = y - (h / 2);
	while (delay++ < 50000)
		mlx_put_image_to_window(game->mlx, game->win, img, x, y);
	exit_cleanly(game);
}

void	move_player(t_game *game, int x, int y, char dir)
{
	game->dir = dir;
	game->img->curr_player_frame = (game->img->curr_player_frame + 1) % 3;
	if (game->map[y][x] == 'C')
		game->collectibles--;
	if (game->collectibles == 0)
		ft_init2(game);
	if (x == game->exit_x && y == game->exit_y)
		game->inexit = 1;
	else if (game->inexit && game->map[y][x] != '1')
		game->inexit = 0;
	if (game->map[y][x] == '1')
		return ;
	game->move_count++;
	if ((game->map[y][x] == 'E'
		&& game->collectibles == -1) || game->map[y][x] == 'G')
	{
		mlx_clear_window(game->mlx, game->win);
		game_ends(game, x, y);
	}
	game->map[y][x] = 'P';
	game->map[game->player_y][game->player_x] = '0';
	(1) && (game->player_x = x, game->player_y = y, game->dir = dir);
	render_map(game);
}

int	f(int keycode, t_game *game)
{
	int			x;
	int			y;

	x = game->player_x;
	y = game->player_y;
	if (keycode == XK_Down || keycode == XK_S || keycode == XK_s)
		(move_player(game, x, y + 1, 'd'));
	else if (keycode == XK_Up || keycode == XK_W || keycode == XK_w)
		(move_player(game, x, y - 1, 'u'));
	else if (keycode == XK_Right || keycode == XK_D || keycode == XK_d)
		(move_player(game, x + 1, y, 'l'));
	else if (keycode == XK_Left || keycode == XK_A || keycode == XK_a)
		(move_player(game, x - 1, y, 'r'));
	else if (keycode == XK_Escape || keycode == XK_Q || keycode == XK_q)
		(write(2, "Is this map hard for you ?\n", 27), exit_cleanly(game));
	return (0);
}

int	render_map(t_game *game)
{
	int (x), y;
	(1) && (x = 0, y = 0, game->boss_i = 0);
	while (y < game->rows * IMG_H)
	{
		while (x < game->cols * IMG_W)
		{
			if (game->map[y / IMG_H][x / IMG_H] == '0')
				draw_img(game, game->img->floor, x, y);
			if (game->map[y / IMG_H][x / IMG_W] == 'E')
				check_exit(game, 1);
			if (game->map[y / IMG_W][x / IMG_W] == '1')
				draw_img(game, game->img->wall, x, y);
			else if (game->map[y / IMG_H][x / IMG_W] == 'G')
				(draw_img(game, NULL, x, y), game->boss_i++);
			else if (game->map[y / IMG_H][x / IMG_W] == 'P')
				draw_img(game, NULL, x, y);
			else if (game->map[y / IMG_H][x / IMG_W] == 'C')
				draw_img(game, game->img->collectible, x, y);
			x += IMG_W;
		}
		(1) && (y += IMG_H, x = 0, put_str(game));
	}
	check_exit(game, 0);
	return (0);
}
