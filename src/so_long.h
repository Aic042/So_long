/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:55:47 by root              #+#    #+#             */
/*   Updated: 2025/03/13 09:39:19 by aingunza         ###   ########.fr       */
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
# define ERR_ASSETS "Check the assets folder"
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
# define T 128

typedef struct player
{
	int	count_collec;
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
	mlx_texture_t	*p1;
	mlx_texture_t	*exit;
	mlx_texture_t	*coin;
}	t_textures;

typedef struct img
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*p1;
	mlx_image_t	*exit;
	mlx_image_t	*coin;
}	t_img;

typedef struct t_map
{
	char	**map2d;
	int		rows;
	int		columns;
}	t_map;

typedef struct game
{
	mlx_t		*mlx;
	t_img		*img;
	t_textures	*textures;
	t_map		*map;
	t_window	*window;
	t_player	*player;
	int			map_width;
	int			map_height;
	int			total_colec;
}	t_game;

//------------------ Functions

// Collectionables
int		collect_count(t_game *game);
void	coin_collecter(t_game *game);
// Endgame
void	ft_end_game(t_game *game);
void	free_player(t_game *game);
void	free_map(t_game *game);
void	free_textures(t_game *game);
void	free_img(t_game *game);
// Path Checker
char	**duplicate_map(t_game *game);
void	free_duplicate_map(char **map, int rows);
int		element_counter(t_game *game, char **map_cpy, int *collec, int *exit);
int		ft_file_validator_map(t_game *game);
void	ft_flood_doer(t_game *game, int y, int x, char **map);
// Map Checker
int		ft_map_empty(char **map);
int		ft_validate_walls(t_game *game);
int		validate_map(char **map, t_game *game);
//Map Checker_2
int		ft_check_counts(int E, int P, int C);
int		find_initial_position(t_game *game);
int		ft_file_validator_map(t_game *game);
// Wall Checker
int		is_row_surrounded_by_walls(char	*row);
int		are_row_lengths_consistent(char	**map, int rows);
int		map_corners(char **map, int rows);
int		is_row_all_walls(char *row);
int		wall_checker(t_game *game);
//The map
void	map_size(t_game *game, char **map);
void	ft_validate_file(char	*map_path);
char	**ft_read_map(char	*map_path);
// Textures
void	ft_boot_img(t_game *game);
void	img_to_textures(t_game *game);
void	draw_floor(t_game *game);
void	draw_map(t_game *game);
// Movement
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
void	ft_up(t_game *game);
void	ft_my_hook(mlx_key_data_t keydata, void	*param);
// Main Entry
int		init_game(t_game *game);
void	null_settlers(t_game *game);
int		dealbreakers(t_game *game);
int		main(int argc, char **argv);

#endif