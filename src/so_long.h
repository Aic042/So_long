/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:55:47 by root              #+#    #+#             */
/*   Updated: 2025/02/27 11:15:42 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/ft_printf.h"
#include "../lib/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//--------------------Macros-----------------------------

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 4000

//---------------------Errors-----------------------------
#define Err_Music "Error: Failed to stop the music or VLC was not running."
#define E_WALLS "Check_pathChecker"
#define Err_Mem "There's a memory error. Gotta go back to check those leaks ."
#define	Err_assets
#define Err_arg "There aren't 2 arguments :("
#define Err_map "map failing, we did not play Mario Maker enough"
#define	Err_File "What have you done to the file "
#define Err_Ber	"This is no .ber file :("
#define Err_path "There is no correct path. Gotta go back to map making 😥"
#define Wall '1'
#define Floor '0'
#define Collec 'C'
#define Player 'P'
#define Exit 'E' 
#define Tile_Size 64

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
	int count_collect;
    int move_count;
    int x;
    int y;
} t_player;

typedef struct windows
{
	mlx_t	*mlx;
	int		windows_height;
	int		windows_width;
} t_window;

typedef struct textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
} t_textures;

typedef struct images
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t *exit;
	mlx_image_t	*collectible;
} t_images;

typedef struct t_map
{
	char **map2d;
	int	rows;
	int columns;
} t_map;


typedef struct game
{
	t_images	*images;
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
void ft_path_checker_checker(t_game *game);
// void ft_validate_map(t_game *game);
void find_initial_position(t_game *game);

// Textures
void ft_boot_images(t_game *game);
void ft_clean_old_textures(t_game *game);
void images_to_textures(t_game *game);
void draw_map(t_game *game);

// Map Checker
int	 ft_count_strings(char **map);
void ft_check_counts(int E, int P, int C);
void ft_check_map_validity(char *line);
void ft_parse_line(char *line, int *E, int *P, int *C);
void ft_validate_line_length(char *str_map);
void ft_flood_doer(t_game *game, int y, int x);
int ft_file_validator_map(t_game *game);
int ft_map_empty(t_game *game);

// Movement
void ft_down(t_game *game);
void ft_left(t_game *game);
void ft_right(t_game *game);
void ft_up(t_game *game);
void ft_my_hook(mlx_key_data_t keydata, void* param);

// Map Reader
char **ft_read_map(char *map_path);
void ft_validate_file(char *map_path);
void free_map(t_game *game);

// Main Entry
void ft_end_game(t_game *game);
void ft_my_hook(mlx_key_data_t keydata, void* param);

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
