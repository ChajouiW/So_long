/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanexit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:25:12 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/24 19:47:58 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_itoa(long n)
{
	long	i;
	int		c;
	char	*s;
	char	*tmp;

	(1) && (i = n, c = 0);
	while (i)
	{
		c++;
		i /= 10;
	}
	if (n == 0)
		c++;
	s = malloc(sizeof(char ) * (c + 1));
	if (!s)
		return (NULL);
	i = c;
	s[i--] = '\0';
	while (i >= 0)
	{
		s[i--] = (n % 10) + '0';
		n /= 10;
	}
	tmp = ft_strjoin("Moves counter : ", s);
	return (free(s), tmp);
}

int	put_str(t_game *game)
{
	game->str = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->win, 20, 30, 0XFFFFFF, game->str);
	free(game->str);
	return (0);
}

void	destroy(t_game *game, void **images, int fre)
{
	int	i;

	i = 0;
	while (images[i])
		mlx_destroy_image(game->mlx, images[i++]);
	if (fre)
		free(images);
}

void	to_destroy(t_game *game)
{
	if (game->img->player_d)
		destroy(game, game->img->player_d, 1);
	if (game->img->player_l)
		destroy(game, game->img->player_l, 1);
	if (game->img->player_r)
		destroy(game, game->img->player_r, 1);
	if (game->img->player_u)
		destroy(game, game->img->player_u, 1);
	if (game->img->boss)
		destroy(game, game->img->boss, 1);
	if (game->img->boss2)
		destroy(game, game->img->boss2, 1);
	if (game->img->exitopening)
		destroy(game, game->img->exitopening, 1);
}

int	exit_cleanly(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->img->floor);
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_image(game->mlx, game->img->collectible);
	to_destroy(game);
	while (i < 5)
		mlx_destroy_image(game->mlx, game->img->exit[i++]);
	mlx_destroy_image(game->mlx, game->img->lost);
	mlx_destroy_image(game->mlx, game->img->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free(game->map, 0);
	free(game->img);
	free(game->mlx);
	exit(15);
	return (0);
}
