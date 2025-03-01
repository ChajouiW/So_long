/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:43:40 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/28 22:28:06 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check(t_game *game, int exit, char dir)
{
	if (exit)
	{
		if (dir == 'u')
			game->img_ptr = game->img->exit[2];
		else if (dir == 'd')
			game->img_ptr = game->img->exit[1];
		else if (dir == 'l')
			game->img_ptr = game->img->exit[3];
		else if (dir == 'r')
			game->img_ptr = game->img->exit[4];
	}
	else
	{
		if (dir == 'u')
			game->img_ptr = game->img->player_u;
		else if (dir == 'd')
			game->img_ptr = game->img->player_d;
		else if (dir == 'l')
			game->img_ptr = game->img->player_l;
		else if (dir == 'r')
			game->img_ptr = game->img->player_r;
	}
}

void	move_p(t_game *game, int x, int y, char dir)
{	
	if (game->map[y][x] == 'C')
	{
		game->collectibles--;
		game->map[y][x] = '0';
	}
	if (game->collectibles == 0)
		ft_init2(game);
	check(game, 0, dir);
	if (game->map[y][x] == '1')
	{
		if (game->map[game->player_y][game->player_x] == 'E')
			check(game, 1, dir);
		return ;
	}
	else if (game->map[y][x] == 'E'
			&& game->collectibles == -1)
		exit_cleanly(game, 0);
	else if (game->map[y][x] == 'E')
		check(game, 1, dir);
	game->dir = dir;
	game->player_x = x;
	game->player_y = y;
	game->moves++;
}

int	f(int keycode, t_game *game)
{
	if (keycode == XK_Down || keycode == XK_S || keycode == XK_s)
		(move_p(game, game->player_x, game->player_y + 1, 'd'));
	else if (keycode == XK_Up || keycode == XK_W || keycode == XK_w)
		(move_p(game, game->player_x, game->player_y - 1, 'u'));
	else if (keycode == XK_Right || keycode == XK_D || keycode == XK_d)
		(move_p(game, game->player_x + 1, game->player_y, 'r'));
	else if (keycode == XK_Left || keycode == XK_A || keycode == XK_a)
		(move_p(game, game->player_x - 1, game->player_y, 'l'));
	else if (keycode == XK_Escape || keycode == XK_Q || keycode == XK_q)
		exit_cleanly(game, 1);
	move(game, game->player_x, game->player_y);
	return (0);
}
