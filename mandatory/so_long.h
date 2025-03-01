/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:28:59 by mochajou          #+#    #+#             */
/*   Updated: 2025/03/01 03:15:38 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <X11/keysym.h>
# include "/usr/include/minilibx-linux/mlx.h"

# define IMG_W 64
# define IMG_H 64

typedef struct s_img
{
	void	*player_u;
	void	*player_d;
	void	*player_l;
	void	*player_r;
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*exit[5];
}	t_img;

typedef struct s_game
{
	t_img	*img;
	void	*mlx;
	void	*img_ptr;
	void	*win;
	char	**map;
	char	dir;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		exit;
	int		collectibles;
	int		moves;
	int		last_count;
}	t_game;

typedef struct s_direction
{
	int	x;
	int	y;
}	t_direction;

typedef struct s_counter
{
	int	e;
	int	c;
	int	p;
}	t_count;

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}	t_node;

int			ft_strlen(const char *s);
int			is_valid(t_game *game);
int			bfs(t_game *game, char **copy);
void		ft_putnbr(int n);

void		gaming(t_game *game);
void		ft_init(t_game *game);
void		ft_init2(t_game *game);

int			file_check(const char *file, const char *ext);
int			f(int keycode, t_game *game);
int			exit_cleanly(t_game *game, int exit);

void		render_map(t_game *game, int x, int y);
void		move(t_game *game, int x, int y);

void		handle_exit(t_game *game, int x, int y, char dir);

void		move_on(t_game *game, char **copy, t_node **queue, t_node *current);

void		enqueue(t_node **q, int x, int y);
t_node		*creat_node(int x, int y);
t_node		*dequeue(t_node **queue);
t_direction	*set_dirs(void);

void		ft_free(char **s, int index);

#endif
