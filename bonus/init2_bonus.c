/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:56:21 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/24 18:48:40 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_frames2(t_game *game, int w, int h)
{
	game->img->player_u = malloc(sizeof(void *) * (3 + 1));
	if (!game->img->player_u)
		(write(2, "Error\nmalloc fail\n", 18), exit_cleanly(game));
	game->img->player_u[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/back/frames14.xpm", &w, &h);
	game->img->player_u[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/back/frames15.xpm", &w, &h);
	game->img->player_u[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/back/frames16.xpm", &w, &h);
	game->img->player_u[3] = NULL;
	game->img->player_d = malloc(sizeof(void *) * (3 + 1));
	if (!game->img->player_d)
		(write(2, "Error\nmalloc fail\n", 18), exit_cleanly(game));
	game->img->player_d[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/front/frames2.xpm", &w, &h);
	game->img->player_d[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/front/frames3.xpm", &w, &h);
	game->img->player_d[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/front/frames2.xpm", &w, &h);
	game->img->player_d[3] = NULL;
}

void	player_frames(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img->player_l = malloc(sizeof(void *) * (3 + 1));
	if (!game->img->player_l)
		(write(2, "Error\nmalloc fail\n", 18), exit_cleanly(game));
	game->img->player_l[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/right/frames10.xpm", &img_w, &img_h);
	game->img->player_l[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/right/frames11.xpm", &img_w, &img_h);
	game->img->player_l[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/right/frames12.xpm", &img_w, &img_h);
	game->img->player_l[3] = NULL;
	game->img->player_r = malloc(sizeof(void *) * (3 + 1));
	if (!game->img->player_r)
		(write(2, "Error\nmalloc fail\n", 18), exit_cleanly(game));
	game->img->player_r[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/left/frames6.xpm", &img_w, &img_h);
	game->img->player_r[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/left/frames7.xpm", &img_w, &img_h);
	game->img->player_r[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/left/frames8.xpm", &img_w, &img_h);
	game->img->player_r[3] = NULL;
	player_frames2(game, img_w, img_h);
}

void	frames_from2(t_game *game, int w, int h)
{
	game->img->player_l[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames6.xpm", &w, &h);
	game->img->player_l[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames7.xpm", &w, &h);
	game->img->player_l[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames8.xpm", &w, &h);
	game->img->player_l[3] = NULL;
	game->img->player_r[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames10.xpm", &w, &h);
	game->img->player_r[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames11.xpm", &w, &h);
	game->img->player_r[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames12.xpm", &w, &h);
	game->img->player_r[3] = NULL;
}

void	frames_form(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img->player_u[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames14.xpm", &img_w, &img_h);
	game->img->player_u[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames15.xpm", &img_w, &img_h);
	game->img->player_u[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames16.xpm", &img_w, &img_h);
	game->img->player_u[3] = NULL;
	game->img->player_d[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames2.xpm", &img_w, &img_h);
	game->img->player_d[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames4.xpm", &img_w, &img_h);
	game->img->player_d[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/kyube_form/frames3.xpm", &img_w, &img_h);
	game->img->player_d[3] = NULL;
	frames_from2(game, img_w, img_h);
}

void	player_in(t_game *game, int form)
{
	if (form)
		frames_form(game);
	else
		player_frames(game);
}
