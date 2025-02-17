/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:55:47 by root              #+#    #+#             */
/*   Updated: 2025/02/17 20:03:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# include "MLX42/MLX42.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "../libutils/libft.h"

//--------------------Macros-----------------------------

#define E_WALLS "Check_pathChecker"



//---------------------Errors-----------------------------
#define Err_Music "Error: Failed to stop the music or VLC was not running."
#define Err_Mem "There's a memory error. Gotta go back to check those leaks ."
#define	Err_assets
#define Err_arg
#define Err_map "map failing, we did not play Mario Maker enough"
#define	Err_File "What have you done to the file "
#define Err_Ber
#define Err_path "There is no correct path. Gotta go back to map making 😥"
#define Wall '1'
#define Collec 'C'
#define Player 'P'
#define Exit 'E' 
#define Tile_Size '64'

//--------------------Structs----------------------------

/*
	typedef struct effects
	{
		int lava_deadly;
		int water_deadly;
		int is_switched;
		int times_switched;
	} t_effect;
*/
typedef struct player
{
	int move_count;
	int player_sprites[3];
} t_player;

typedef struct windows
{
	mlx_t	*mlx;
	int		windows_height;
	int		windows_width;
} t_window;


typedef struct textures
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t *exit;
} t_textures;

typedef struct t_map
{
	int **map;
	int	rows;
	int columns;
} t_map;


typedef struct game
{
	t_textures  *textures;
	t_map		*map;
	t_window	*window;
	t_player	*player;
//	t_effect	*effects;
} t_game;




//------------------ Functions

// Wall Checker
int  are_row_lengths_consistent(char **map, int rows);
void ft_validate_walls(t_game *game);
int  is_row_surrounded_by_walls(char *row);
int  map_corners(char **map, int rows);

// Character Validator
void char_validator(void);
int  is_valid_char(char c);

// Collectionables
int collect_count(t_game *game);


// Path Checker
void end_game(t_game *game);
void ft_path_checker_checker(void);
void ft_validate_2dmap(t_game *game);

// Textures
void ft_boot_textures(t_game *game);
void ft_clean_old_textures(t_game *game);

// Map Checker
void ft_check_counts(int E, int P, int C);
void ft_check_map_validity(char *line);
void ft_parse_line(void);
void ft_validate_line_length(char *str_map);

// Movement
void ft_down(t_game *game);
void ft_hook(mlx_key_data_t keydata, void* param, t_game *game);
void ft_left(t_game *game);
void ft_right(t_game *game);
void ft_up(t_game *game);


// Map Reader
char *ft_read_map(char *map_path);
void ft_validate_file(char *map_path);

// Main Entry

//------------------Bonus------------------------------//


// Effects
void effect_initializer(t_game *game);
void transform(t_game *game);

// Timer
void ft_timer(uint32_t ms);

// Music
void ft_music(const char *script_path);
void ft_stop_music(void);

// Miscellaneous
void ft_initialize_variables(t_game *game);
void hook(void *param);
void render_tile(t_game *game, char tile, int x, int y);

#endif