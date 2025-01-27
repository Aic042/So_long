/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:45 by root              #+#    #+#             */
/*   Updated: 2025/01/26 14:50:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_hook(mlx_key_data_t keydata, void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		ft_stop_music();
	}	
	if (mlx_is_key_down(mlx, MLX_KEY_UP)|| (mlx_is_key_down(mlx,MLX_KEY_W)))
	ft_up;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx,MLX_KEY_S)))
	ft_down;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx,MLX_KEY_A)))
		ft_left;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || (mlx_is_key_down(mlx,MLX_KEY_D)))
		ft_right;
}
void ft_up(game)
{
		player->instances[0].y -= 5;	
}
void ft_down(game)
{
		player->instances[0].y += 5;	
}
void ft_left(game)
{
		player->instances[0].x -= 5;	
}
void ft_right(game)
{
		player->instances[0].x += 5;	
}