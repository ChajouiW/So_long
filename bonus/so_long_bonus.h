/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochajou <mochajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:28:59 by mochajou          #+#    #+#             */
/*   Updated: 2025/03/01 05:17:11 by mochajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include "get_next_line_bonus.h"
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <X11/keysym.h>
# include "/usr/include/minilibx-linux/mlx.h"

# define IMG_W 64
# define IMG_H 64

typedef struct s_img
{
	void	**player_u;
	void	**player_d;
	void	**player_l;
	void	**player_r;
	void	**boss;
	void	**boss2;
	void	**exitopening;
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*lost;
	void	*win;
	void	*exit[5];
	int		curr_player_frame;
	int		curr_boss_frame;
	int		curr_boss2_frame;
	int		current_exit_frame;
}	t_img;

typedef struct s_game
{
	char	**map;
	char	*str;
	char	dir;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		exit;
	int		inexit;
	int		collectibles;
	int		move_count;
	int		boss_i;
	int		valid;
	void	*mlx;
	void	*win;
	void	*img_ptr;
	t_img	*img;
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

int			is_valid(t_game *game, char *file);
int			put_str(t_game *game);
int			bfs(t_game *game, char **copy);

void		ft_free(char **s, int index);
void		ft_init(t_game *game);
void		ft_init2(t_game *game);
void		gaming(t_game *game);

int			f(int keycode, t_game *game);

int			exit_cleanly(t_game *game);
int			render_map(t_game *game);

void		move(t_game *game, int x, int y);
void		put_to_win(t_game *game, float w, float h, int n);
void		handle_exit(t_game *game, char dir);

void		move_on(t_game *game, char **copy, t_node **queue, t_node *current);
void		draw_img(t_game *game, void *img, int x, int y);
void		player_in(t_game *game, int form);
void		check_exit(t_game *game, int open);
void		destroy(t_game *game, void **images, int fre);

void		enqueue(t_node **q, int x, int y);
t_node		*creat_node(int x, int y);
t_node		*dequeue(t_node **queue);

t_direction	*set_dirs(void);

#endif
