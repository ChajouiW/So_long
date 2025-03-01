/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:26:41 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/28 22:33:02 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_check(const char *file, const char *ext)
{
	size_t	i;
	size_t	j;

	if ((!file || !ext))
		return (0);
	j = 0;
	i = ft_strlen(file) - ft_strlen(ext);
	if (i < 0)
		return (0);
	while (file[i] == ext[j] && ext[j])
	{
		i++;
		j++;
	}
	if (file[i] == '\0')
		return (1);
	return (0);
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

	(1) && (game->rows = 0, line = get_next_line(fd));
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
	close(fd);
	game->map[i] = NULL;
}

int	exit_cleanly(t_game *game, int ext)
{
	int	i;

	i = 0;
	if (!ext)
		ft_putnbr(game->moves + 1);
	else if (!game->moves)
		write(1, "0", 1);
	write(1, "\n", 1);
	mlx_destroy_image(game->mlx, game->img->floor);
	mlx_destroy_image(game->mlx, game->img->player_d);
	mlx_destroy_image(game->mlx, game->img->player_l);
	mlx_destroy_image(game->mlx, game->img->player_r);
	mlx_destroy_image(game->mlx, game->img->player_u);
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_image(game->mlx, game->img->collectible);
	while (i < 5)
		mlx_destroy_image(game->mlx, game->img->exit[i++]);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free(game->map, 0);
	free(game->img);
	free(game->mlx);
	exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
		(write(2, "Usage: ./so_long file_name.ber\n", 31), exit(1));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nInvalid file\n", 19), 1);
	if (!file_check(av[1], ".ber"))
		return (write(2, "file must end with .ber\n", 24), 1);
	read_map(av, &game, fd);
	if (!game.rows)
		(write(2, "Error\nInvalid map\n", 18), exit(1));
	if (!is_valid(&game) || game.rows < 3)
	{
		if (game.map)
			ft_free(game.map, 0);
		exit(1);
	}
	gaming(&game);
	return (0);
}
