/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:45 by root              #+#    #+#             */
/*   Updated: 2024/12/19 12:58:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 1000
#define HEIGHT 1000

static mlx_image_t* player;

// typedef struct player_texture
// {
// 	uint32_t	width;
// 	uint32_t	height;
// 	uint8_t		bytes_per_pixel;
// 	uint8_t*	pixels;
// }	player_texture_t;


void error()
{
    // Handle error
    exit(EXIT_FAILURE);
}

void ft_hook(mlx_key_data_t keydata, void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP)|| (mlx_is_key_down(mlx,MLX_KEY_W)))
		player->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx,MLX_KEY_S)))
		player->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx,MLX_KEY_A)))
		player->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || (mlx_is_key_down(mlx,MLX_KEY_D)))
	{
		player->instances[0].x += 5;
	}
}

