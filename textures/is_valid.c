/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:47:49 by mochajou          #+#    #+#             */
/*   Updated: 2025/02/28 22:37:42 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copy(t_game *game)
{
	int		i;
	char	**copy;

	copy = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->rows)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			(ft_free(copy, i), ft_free(game->map, 0), free(game));
			exit(1);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	valid_line(char *line, t_count *comp, t_game *game, int y)
{
	int		i;
	char	*check;

	i = 0;
	check = "01ECP";
	while (line[i] && line[i] != '\n')
	{
		if (!strchr(check, line[i]))
			return (0);
		if (line[i] == 'P')
			(1) && (comp->p++, game->player_x = i, game->player_y = y);
		else if (line[i] == 'C')
			comp->c++;
		else if (line[i] == 'E')
			(1) && (comp->e++, game->exit_x = i, game->exit_y = y);
		i++;
	}
	return (1);
}

int	check_map(t_game *game, t_count *comp)
{
	int	i;
	int	j;

	(1) && (game->cols = ft_strlen(game->map[0]) - 1, i = 0, j = -1);
	while (i < game->rows)
	{
		if (i == game->rows - 1 && game->map[i][game->cols] != '\0'
				&& game->map[i][game->cols] != '\n')
			return (write(2, "Error\nThe map must be rectangular\n", 34), 0);
		else if (game->cols != (int)ft_strlen(game->map[i]) - 1
			&& i != game->rows - 1)
			return (write(2, "Error\nThe map must be rectangular\n", 34), 0);
		if (!valid_line(game->map[i], comp, game, i))
			return (write(2, "Error\nThe map components error\n", 31), 0);
		while (++j < game->cols)
		{
			if (i == 0 || i == game->rows - 1 || j == 0 || j == game->cols - 1)
				if (game->map[i][j] != '1')
					return (write(2, "Error\nThe map must be closed\n", 30), 0);
		}
		(1) && (i++, j = -1);
	}
	if (comp->c < 1 || comp->p != 1 || comp->e != 1)
		return (write(2, "Error\nThe map not valid\n", 24), 0);
	return (1);
}

int	is_valid(t_game *game)
{
	t_count	comp;

	(1) && (comp.c = 0, comp.e = 0, comp.p = 0);
	if (!check_map(game, &comp))
		return (0);
	game->collectibles = comp.c;
	if (!bfs(game, map_copy(game)))
		return (0);
	return (1);
}
