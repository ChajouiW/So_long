/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:35:08 by mochajou          #+#    #+#             */
/*   Updated: 2025/03/01 00:46:18 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_more_init(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img->exit[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/closedexit.xpm", &img_w, &img_h);
	game->img->exit[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/withexitf.xpm", &img_w, &img_h);
	game->img->exit[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/withexitb.xpm", &img_w, &img_h);
	game->img->exit[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/withexitr.xpm", &img_w, &img_h);
	game->img->exit[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/withexitl.xpm", &img_w, &img_h);
	game->dir = 0;
	game->moves = 0;
	game->last_count = 0;
}

void	ft_init(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img = malloc(sizeof(t_img));
	if (!game->img)
		(write(2, "Error\nmalloc fail\n", 18), exit_cleanly(game, 0));
	game->img->player_u = mlx_xpm_file_to_image(game->mlx,
			"textures/back/frames15.xpm", &img_w, &img_h);
	game->img->player_d = mlx_xpm_file_to_image(game->mlx,
			"textures/front/frames2.xpm", &img_w, &img_h);
	game->img->player_l = mlx_xpm_file_to_image(game->mlx,
			"textures/left/frames6.xpm", &img_w, &img_h);
	game->img->player_r = mlx_xpm_file_to_image(game->mlx,
			"textures/right/frames11.xpm", &img_w, &img_h);
	game->img_ptr = game->img->player_d;
	game->img->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/lava_wall.xpm", &img_w, &img_h);
	game->img->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/black_floor_64.xpm", &img_w, &img_h);
	game->img->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/ramen.xpm", &img_w, &img_h);
	ft_more_init(game);
}

void	ft_init2(t_game *game)
{
	int	img_w;
	int	img_h;

	mlx_destroy_image(game->mlx, game->img->player_d);
	mlx_destroy_image(game->mlx, game->img->player_u);
	mlx_destroy_image(game->mlx, game->img->player_l);
	mlx_destroy_image(game->mlx, game->img->player_r);
	mlx_destroy_image(game->mlx, game->img->exit[0]);
	game->img->player_u = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames14.xpm", &img_w, &img_h);
	game->img->player_d = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames2.xpm", &img_w, &img_h);
	game->img->player_l = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames11.xpm", &img_w, &img_h);
	game->img->player_r = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames6.xpm", &img_w, &img_h);
	game->img->exit[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/exits/exits3.xpm", &img_w, &img_h);
	mlx_put_image_to_window(game->mlx, game->win, game->img->exit[0],
		game->exit_x * IMG_W, game->exit_y * IMG_H);
	game->collectibles = -1;
}
