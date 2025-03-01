/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:47:49 by mochajou          #+#    #+#             */
/*   Updated: 2025/03/01 04:31:43 by mochajou         ###   ########.fr       */
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
	int (i), j, w, h;
	(1) && (game->cols = ft_strlen(game->map[0]) - 1, w = game->cols,
		h = game->rows, i = 0, j = -1);
	while (i < h)
	{
		if (game->map[i][0] == '\0' || game->map[i][0] == '\n')
			return (write(2, "Error\nCheck for empty lines\n", 28), 0);
		if (ft_strlen(game->map[i]) >= game->cols && i == h - 1
			&& game->map[i][w] != '\0' && game->map[i][w] != '\n')
			return (write(2, "Error\nLast line\n", 16), 0);
		if (game->cols != ft_strlen(game->map[i]) - 1 && i != game->rows - 1)
			return (write(2, "Error\nThe map must be rectangular\n", 34), 0);
		if (!valid_line(game->map[i], comp, game, i))
			return (write(2, "Error\nThe map components: 01ECP\n", 32), 0);
		while (++j < w)
		{
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
				if (game->map[i][j] != '1')
					return (write(2, "Error\nThe map must be closed\n", 29), 0);
		}
		(1) && (i++, j = -1);
	}
	if (comp->c < 1 || comp->p != 1 || comp->e != 1)
		return (write(2, "Error\nCheck components count: P C E\n", 36), 0);
	return (1);
}

int	is_valid(t_game *game)
{
	t_count	comp;

	memset(&comp, 0, sizeof(t_count));
	(1) && (comp.c = 0, comp.e = 0, comp.p = 0);
	if (!check_map(game, &comp))
		return (0);
	game->collectibles = comp.c;
	if (!bfs(game, map_copy(game)))
		return (0);
	return (1);
}
