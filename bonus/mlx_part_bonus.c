/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_part_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:41:09 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/27 23:16:57 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation(t_game *game, void **img, int frame, t_direction cord)
{
	long	delay;

	delay = 0;
	if (!img || !img[frame])
		return ;
	mlx_put_image_to_window(game->mlx, game->win, img[frame],
		cord.x, cord.y);
	while (delay < 70000)
		delay++;
}

void	check_exit(t_game *game, int open)
{
	static int (first_time), frames, count;
	t_direction (cord);
	if (open)
	{
		if (game->collectibles <= 0 && !first_time)
		{
			cord.x = game->exit_x * IMG_W;
			cord.y = game->exit_y * IMG_H;
			animation(game, game->img->exitopening, frames, cord);
			if (count++ % 69 == 0)
				frames++;
			(frames > 4) && (first_time = 1);
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img->exit[0],
				game->exit_x * IMG_W, game->exit_y * IMG_H);
	}
	else if (game->map[game->exit_y][game->exit_x] != 'E' && !game->inexit)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit[0],
			game->exit_x * IMG_W, game->exit_y * IMG_H);
		game->map[game->exit_y][game->exit_x] = 'E';
	}
}

void	draw_player(t_game *game, int x, int y)
{
	t_direction	cord;

	cord.x = x;
	cord.y = y;
	if (game->inexit)
		handle_exit(game, game->dir);
	else
	{
		if (game->dir == 'u')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->player_u[game->img->curr_player_frame], x, y);
		else if (game->dir == 'd')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->player_d[game->img->curr_player_frame], x, y);
		else if (game->dir == 'l')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->player_l[game->img->curr_player_frame], x, y);
		else if (game->dir == 'r')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->player_r[game->img->curr_player_frame], x, y);
	}
}

void	draw_boss(t_game *game, int x, int y)
{
	t_direction	cord;

	static int (count1), count2;
	(1) && (cord.x = x, cord.y = y);
	if (game->boss_i % 2)
	{
		if (game->img->curr_boss_frame == 0)
			count1 = 0;
		if (count1 % 69 == 0)
			game->img->curr_boss_frame = (game->img->curr_boss_frame + 1) % 11;
		animation(game, game->img->boss, game->img->curr_boss_frame, cord);
		count1++;
	}
	else
	{
		if (game->img->curr_boss2_frame == 0)
			count2 = 0;
		if (count2 % 67 == 0)
			game->img->curr_boss2_frame = (game->img->curr_boss2_frame + 1) % 5;
		animation(game, game->img->boss2, game->img->curr_boss2_frame, cord);
		count2++;
	}
}

void	draw_img(t_game *game, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x, y);
	else if (game->map[y / IMG_W][x / IMG_H] == 'P')
		draw_player(game, x, y);
	else if (game->map[y / IMG_W][x / IMG_H] == 'G')
		draw_boss(game, x, y);
}
