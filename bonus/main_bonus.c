/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:26:41 by mochajou          #+#    #+#             */
/*   Updated: 2025/03/01 05:25:47 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_to_win(t_game *game, float w, float h, int n)
{
	int		x;
	int		y;
	void	*img;

	img = NULL;
	if (n == 1)
		img = mlx_xpm_file_to_image(game->mlx, "textures/hhh.xpm", &x, &y);
	else if (n == 2)
		img = mlx_xpm_file_to_image(game->mlx, "textures/konoha.xpm", &x, &y);
	x = game->cols * IMG_W;
	x /= 2;
	x = x - (w / 2);
	y = game->rows * IMG_W;
	y /= 2;
	y = y - (h / 2);
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
	usleep(1000000);
	mlx_destroy_image(game->mlx, img);
}

void	gaming(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->cols * IMG_W,
			game->rows * IMG_H, "so_long");
	put_to_win(game, 163, 309, 1);
	put_to_win(game, 354, 250, 2);
	ft_init(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, f, game);
	mlx_hook(game->win, 17, 1L << 17, exit_cleanly, game);
	mlx_loop_hook(game->mlx, render_map, game);
	mlx_loop(game->mlx);
}

void	ft_free(char **s, int index)
{
	if (index)
	{
		while (index)
			free(s[index--]);
		free(s);
		return ;
	}
	while (s[index])
	{
		free(s[index]);
		index++;
	}
	free(s);
}

void	read_map(char	**av, t_game *game, int fd)
{
	int		i;
	char	*line;

	game->rows = 0;
	line = get_next_line(fd);
	if (!line)
		return ;
	while (line)
	{
		game->rows++;
		(free(line), line = get_next_line(fd));
	}
	game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		(free(game->map), exit(1));
	(1) && (close(fd), fd = open(av[1], O_RDONLY), i = -1);
	while (++i < game->rows)
		game->map[i] = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	(close(fd), game->map[i] = NULL);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
		(write(2, "./so_long file_name.ber\n", 24), exit(1));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nInvalid file\n", 19), 1);
	read_map(av, &game, fd);
	if (!game.rows)
		(write(2, "Error\nEmpty map!\n", 17), exit(1));
	if (!is_valid(&game, av[1]))
	{
		ft_free(game.map, 0);
		exit(3);
	}
	gaming(&game);
}
