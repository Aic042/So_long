/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:55:47 by root              #+#    #+#             */
/*   Updated: 2024/12/17 16:56:43 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include "ft_printf/ft_printf.h"

typedef struct textures
{
    	mlx_image_t		*bush;
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

ft_error(char *str, int error);



#endif