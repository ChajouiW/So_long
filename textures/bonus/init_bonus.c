/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:35:08 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/24 19:56:09 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	boss_frames2(t_game *game, int img_w, int img_h)
{
	mlx_clear_window(game->mlx, game->win);
	game->img->boss[9] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada10.xpm", &img_w, &img_h);
	game->img->boss[10] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada11.xpm", &img_w, &img_h);
	game->img->boss[11] = NULL;
	game->img->boss2 = malloc(sizeof(void *) * (5 + 1));
	if (!game->img->boss2)
		(write(2, "Error\nmalloc fail\n", 18), exit_cleanly(game));
	game->img->boss2[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/frames1.xpm", &img_h, &img_w);
	game->img->boss2[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/frames2.xpm", &img_h, &img_w);
	game->img->boss2[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/frames3.xpm", &img_h, &img_w);
	game->img->boss2[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/frames4.xpm", &img_h, &img_w);
	game->img->boss2[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/frames5.xpm", &img_h, &img_w);
	game->img->boss2[5] = NULL;
}

void	boss_frames(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img->boss = malloc(sizeof(void *) * (11 + 1));
	if (!game->img->boss)
		(write(2, "Error\nmalloc fail\n", 18), exit_cleanly(game));
	game->img->boss[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada1.xpm", &img_w, &img_h);
	game->img->boss[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada2.xpm", &img_w, &img_h);
	game->img->boss[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada3.xpm", &img_w, &img_h);
	game->img->boss[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada4.xpm", &img_w, &img_h);
	game->img->boss[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada5.xpm", &img_w, &img_h);
	game->img->boss[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada6.xpm", &img_w, &img_h);
	game->img->boss[6] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada7.xpm", &img_w, &img_h);
	game->img->boss[7] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada8.xpm", &img_w, &img_h);
	game->img->boss[8] = mlx_xpm_file_to_image(game->mlx,
			"textures/Boss/mada9.xpm", &img_w, &img_h);
	boss_frames2(game, img_w, img_h);
}

void	ft_more_init(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img->exit[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/withexitl.xpm", &img_w, &img_h);
	game->img->exit[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/withexitr.xpm", &img_w, &img_h);
	game->img->exitopening = malloc(sizeof(void *) * (4 + 1));
	if (!game->img->exitopening)
		(write(2, "Error\nmalloc fail\n", 18), exit_cleanly(game));
	game->img->exitopening[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/closedexit.xpm", &img_w, &img_h);
	game->img->exitopening[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/exits1.xpm", &img_w, &img_h);
	game->img->exitopening[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/exits2.xpm", &img_w, &img_h);
	game->img->exitopening[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/exits3.xpm", &img_w, &img_h);
	game->img->exitopening[4] = NULL;
	game->img->lost = mlx_xpm_file_to_image(game->mlx,
			"textures/lost.xpm", &img_w, &img_h);
	game->img->win = mlx_xpm_file_to_image(game->mlx,
			"textures/win.xpm", &img_w, &img_h);
	game->dir = 'd';
}

void	ft_init(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img = malloc(sizeof(t_img));
	if (!game->img)
		(write(2, "Error\nmalloc fail\n", 18), exit_cleanly(game));
	(player_in(game, 0), boss_frames(game));
	(1) && (game->img_ptr = game->img->player_d[0],
	game->img->curr_player_frame = 0, game->valid = 0,
	game->img->curr_boss_frame = 0, game->img->curr_boss2_frame = 0,
	game->inexit = 0, game->exit = 0, game->move_count = 0);
	game->img->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/lava_wall.xpm", &img_w, &img_h);
	game->img->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/black_floor_64.xpm", &img_w, &img_h);
	game->img->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/ramen.xpm", &img_w, &img_h);
	game->img->exit[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/closedexit.xpm", &img_w, &img_h);
	game->img->exit[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/withexitf.xpm", &img_w, &img_h);
	game->img->exit[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/withexitb.xpm", &img_w, &img_h);
	ft_more_init(game);
}

void	ft_init2(t_game *game)
{
	int	w;
	int	h;

	mlx_destroy_image(game->mlx, game->img->exit[0]);
	destroy(game, game->img->player_d, 0);
	destroy(game, game->img->player_u, 0);
	destroy(game, game->img->player_l, 0);
	destroy(game, game->img->player_r, 0);
	player_in(game, 1);
	game->img->exit[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/exits3.xpm", &w, &h);
	game->collectibles = -1;
}
