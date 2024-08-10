/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:32:23 by jfazi             #+#    #+#             */
/*   Updated: 2024/05/07 14:21:09 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

//// I N C L U D E S //////
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"

////// D E F I N E ////////
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.05

# define CAMERA_LENGHT 1

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 600

# define TEXTURE_WIDTH 500
# define TEXTURE_HEIGHT 500

# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define RED		"\033[91m"
# define GREEN		"\033[92m"
# define YELLOW		"\033[93m"
# define BLUE		"\033[94m"
# define MAGENTA	"\033[95m"
# define CYAN		"\033[96m"

# define COLOR_ORANGE 0x00F7702C
# define COLOR_VIOLET 0x00F42CF7

# define ERROR_MSG "Error\n"
# define ERROR_ARGC_MSG "Error\nInvalid number of arguments\n"
# define ERROR_FD_MSG "File can't be open\n"
# define ERROR_INIT_MSG "Error\nInitialisation failed\n"
# define ERROR_CHAR_MSG "Map contains invalid character\n"
# define ERROR_MAP_MALLOC_MSG "Map allocation malfunction\n"
# define ERROR_SPAWN_MSG "Player spawn position not found\n"
# define ERROR_RAYCAST_DISTANCE_MSG "Raycast distance equal to 0\n"
# define ERROR_EXT_MSG "ERROR\nInvalid file extension\n"

# define KEYCODE_A 97
# define KEYCODE_W 119
# define KEYCODE_S 115
# define KEYCODE_D 100
# define KEYCODE_LEFT_ARROW 65361
# define KEYCODE_RIGHT_ARROW 65363
# define KEYCODE_ESC 65307

# define MAP_WALL '1'
# define MAP_EMPTY '0'

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

/// S T R U C T U R E S ///

typedef enum e_direction
{
	NORD,
	SOUTH,
	EAST,
	WEST,
	NONE
}			t_direction;

typedef struct s_vector2
{
	double			x;
	double			y;
}	t_vector2;

typedef struct s_vector2Int
{
	int				x;
	int				y;
}	t_vector2int;

typedef struct s_player
{
	t_vector2		position;
	t_vector2		rotation;
	t_vector2		plane;
}					t_player;

typedef struct s_map
{
	char			**layout;
	char			**sqr_layout;
	t_vector2int	dimensions;

	char			*nord_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;

	char			*ground_color;
	char			*ceilling_color;
	char			**ground_color_tab;
	char			**ceilling_color_tab;

	t_vector2int	player_spawn;
	t_direction		player_spawn_rotation;
}	t_map;

typedef struct s_inputs
{
	t_bool			forward_movement;
	t_bool			right_movement;
	t_bool			downward_movement;
	t_bool			left_movement;

	t_bool			right_rotation;
	t_bool			left_rotation;

	t_bool			close_window;
}	t_inputs;

typedef struct s_raycast
{
	t_vector2		position;
	t_vector2		direction;
	t_vector2		side_dist;
	t_vector2		delta_dist;
	t_vector2int	step;
	t_vector2int	map;
	double			distance;
	t_direction		wall_side_hit;
	t_bool			hit;
}					t_raycast;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llngth;
	int		endn;
}			t_image;

typedef struct s_parsing
{
	int			file_taille;
	int			arg_taille;
	char		**file;
}				t_parsing;

typedef struct s_data
{
	t_player		*player;
	t_map			*map;
	t_image			*rendering;
	t_parsing		*pars;
	t_inputs		*inputs;

	double			camera_x;

	t_image			*nord_img;
	t_image			*south_img;
	t_image			*east_img;
	t_image			*west_img;

	int				ceilling_color;
	int				floor_color;

	t_vector2int	texture;
	void			*mlx;
	void			*mlx_win;
}					t_data;

typedef struct s_copy
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*dest;
	int		flag;
}			t_copy;

typedef struct s_new_map
{
	int		i;
	int		tmp_x;
	int		tmp_y;
	int		max_len;
	char	*str;
	char	**tmp;
}			t_new_map;

typedef struct s_column
{
	int		y_texture;
	double	step;
	double	tex_pos;
	int		color;
	int		line_height;
	int		draw_start;
	int		tex_x;
	int		draw_end;
	double	wall_x;
}			t_column;

/////// P R O T O T Y P E S //////////

// inputs.c
int				register_inputs(int _keycode, t_data *_data);
int				release_inputs(int _keycode, t_data *_data);
void			clear_inputs(t_inputs *_inputs);

// init.c
t_bool			init_data(t_data *_data, char **_argv);
void			init_player(t_data *_data);
void			init_map(t_data *_data, char **_argv);
void			init_rendering(t_data *_data);
void			init_textures(t_data *_data);
void			init_parsing(t_data *_data, char **_argv);
void			init_colors(t_data *_data);

// player.c
void			move_player(t_data *_data);
void			rotate_left(t_data *_data);
void			test_player(t_data *_data);
void			rotate_right(t_data *_data);
t_bool			can_move_player(t_data *_data, t_bool plus_x,
					t_bool plus_y, t_vector2 _axis);

// player2.c
int				move(t_data *_data);
void			move_forward(t_data *_data);
void			move_backward(t_data *_data);
void			move_left(t_data *_data);
void			move_right(t_data *_data);

// direction.c
t_direction		rotate_direction(t_bool _rotate_left, t_direction _direction);
t_direction		convert_char_to_direction(char c);
char			*convert_direction_to_string(t_direction _direction);
t_vector2		convert_direction_to_vector(t_direction _direction);

//map.c
t_bool			argv_to_map(char **_argv, t_data *_data);
t_bool			calculate_map_width(char **_argv, t_data *_data);
t_bool			calculate_map_height(char **_argv, t_data *_data);
t_bool			is_in_a_wall(t_data *_data, t_vector2 _position);
t_bool			is_inside_map_dimensions(t_data *_data, t_vector2 _position);
t_bool			is_inside_map_dimensions_int(t_data *_data,
					t_vector2int _position);

// map_contains_correct_char.c
t_bool			map_contains_correct_char(char **_argv);

// map_find_player_spawn.c
t_bool			map_find_player_spawn(t_data *_data);

// vector2.c
double			vector2_distance(t_vector2 a, t_vector2 b);
t_vector2int	vector2_to_vector2int(t_vector2 _vector2);
void			vector2int_set(t_vector2int *_vector2, int x, int y);
void			vector2_set(t_vector2 *_vector2, double x, double y);

// raycast.c
double			cast_raycast(t_data *_data, t_raycast *_raycast);
void			set_delta_dist(t_raycast *_raycast);
void			move_raycast(t_raycast *_raycast, t_data *_data);
void			set_raycast_step_and_side_dist(t_raycast *_raycast);
t_bool			is_x_more_close_to_int_than_y(t_vector2 _vec);
void			raycasting(t_data *_data);

// rendering.c
void			draw_pixel(t_image *_img, int x, int y, int _color);
void			draw_rectangle(t_data *_data, t_vector2int _position,
					t_vector2int _dimensions, int _color);
void			draw_rectangle2(t_data *_data, t_vector2int _position,
					t_vector2int _dimensions, int _color);
void			draw_vertical_line(t_data *_data, int x, t_raycast *_raycast);
void			clear_image(t_data *_data);
void			rendering(t_data *_data);
int				get_pixel(t_image *_image, int x, int y);

// minimap.c
void			draw_minimap(t_data *_data);

// parsing.c
void			file_manager(char **_argv, t_data *_data);
char			*copy_texture(t_data *_data, char *str, char *nswd);
char			*copy_colors(t_data *_data, char *str, char color);
void			check_doubl(t_data *_data);
void			check_valid(t_data *_data);
char			**check_color_valid(t_data *_data, char *str);
void			count_arg(t_data *_data);
void			recup_map(t_data *_data);
void			parse_map(t_data *_data);
void			map_is_close(t_data *_data);
int				calculate_max_len(t_data *_data);
void			new_map(t_data *_data);
void			check_doubl2(t_data *_data, int *k, int i, int j);
void			check_valid2(t_data *_data, int i, int j);
char			*copy_line(char *str, int len);
void			recup_file(char **_argv, t_data *_data);
int				calculate_file(char **_argv, t_data *_data);

////free xav toussa toussa
void			panpan(t_data *_data, char *str);
int				panpan2(void *_data);
void			free_string_array(char **array, size_t size);

///// G N L ///////////
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);
char			*ft_vide(char *dest);
char			*ft_free(char *buffer, char *buf);
char			*ft_read(int fd, char *temp, char *line);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen(const char *str);
///////////////////////////////
#endif