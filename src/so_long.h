/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:55:47 by root              #+#    #+#             */
/*   Updated: 2025/01/27 22:01:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define E_WALLS "Check_pathChecker"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "../libutils/libft.h"

#define Err_Music
#define Err_Mem
#define	Err_assets
#define Err_arg
#define Err_map
#define	Err_File
#define Err_Ber
#define Err_path "There is no correct path. Gotta go back to map making 😥"


typedef struct textures
{
    mlx_image_t		*player;
	mlx_image_t		*squirrel;
	mlx_image_t		*acorn;
	mlx_image_t		*tree;
	mlx_image_t		*floor;
} t_textures;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map_2d;
	int				rows;
	int				columns;
	t_textures		assets;
	t_textures		old_assets;
	mlx_t			*window;
	int				move_count;
	int				m_flag;
	int				c_flag;
	int				c_count;
	int				state;
	bool			exit;
	int				screen_x;
	int				screen_y;
	bool			exit_flag;
}					t_game;

void ft_error(char *str, int error);
void ft_stop_music(void);
void ft_music(const char *script_path);



#endif