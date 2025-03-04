/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:55:47 by root              #+#    #+#             */
/*   Updated: 2025/03/04 11:41:22 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//--------------------Macros-----------------------------

# define TRUE 0
# define FALSE 1
# define BUFFER_SIZE 4000

//---------------------Errors-----------------------------
# define ERR_MUSIC "Error: Failed to stop the music or VLC was not running.\n"
# define E_WALLS "Check_pathChecker\n"
# define ERR_MEM "There's a memory error. Gotta go back to check those leaks.\n"
# define ERR_ASSETS
# define ERR_ARG "There aren't 2 arguments :(\n"
# define ERR_MAP "map failing, we did not play Mario Maker enough\n"
# define ERR_FILE "What have you done to the file\n"
# define ERR_BER "This is no .ber file :(\n"
# define ERR_PATH "There is no correct path. Gotta go back to map making 😥\n"
# define WALL '1'
# define FLOOR '0'
# define COLLEC 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define T_SI 64

//--------------------Structs----------------------------

/*
	typedef struct effects
	{
		int	lava_deadly;
		int	water_deadly;
		int	is_switched;
		int	times_switched;
	}	t_effect;
*/
typedef struct player
{
	int	count_collect;
	int	move_count;
	int	x;
	int	y;
}	t_player;

typedef struct windows
{
	int		windows_height;
	int		windows_width;
}	t_window;

typedef struct textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
}	t_textures;

typedef struct imgs
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
}	t_imgs;

typedef struct t_map
{
	char	**map2d;
	int		rows;
	int		columns;
}	t_map;

typedef struct game
{
	mlx_t		*mlx;
	t_imgs		*imgs;
	t_textures	*textures;
	t_map		*map;
	t_window	*window;
	t_player	*player;
	int			map_width;
	int			map_height;
}	t_game;

//------------------ Functions

// Wall Checker
int		are_row_lengths_consistent(char	**map, int rows);
int		ft_validate_walls(t_game *game);
int		is_row_surrounded_by_walls(char	*row);
int		map_corners(char	**map, int rows);

// Character Validator
void	char_validator(void);
int		is_valid_char(char c);
// Collectionables
int		collect_count(t_game *game);
// Path Checker
void	end_game(t_game *game);
void	ft_path_checker_checker(t_game *game);
// void	ft_validate_map(t_game *game);
int		find_initial_position(t_game *game);
void	map_size(t_game *game, char **map);
// Textures
void	ft_boot_imgs(t_game *game);
void	ft_clean_old_textures(t_game *game);
void	imgs_to_textures(t_game *game);
void	draw_map(t_game *game);
// Map Checker
int		ft_count_strings(char	**map);
int		ft_check_counts(int E, int P, int C);
void	ft_check_map_validity(char	*line);
void	ft_parse_line(char	*line, int *E, int *P, int *C);
void	ft_validate_line_length(char	*str_map);
void	ft_flood_doer(t_game *game, int y, int x);
int		ft_file_validator_map(t_game *game);
int		ft_map_empty(char **map);
int		validate_map(char **map, t_game *game);
// Movement
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
void	ft_up(t_game *game);
void	ft_my_hook(mlx_key_data_t keydata, void	*param);
// Map Reader
char	**ft_read_map(char	*map_path);
void	ft_validate_file(char	*map_path);
void	free_map(t_game *game);
// Main Entry
void	ft_end_game(t_game *game);
void	ft_my_hook(mlx_key_data_t keydata, void *param);
// Miscellaneous
void	ft_initialize_variables(t_game *game);
void	hook(void	*param);
void	render_tile(t_game *game, char tile, int x, int y);
void	free_textures(t_game *game);

#endif