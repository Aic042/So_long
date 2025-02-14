/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:45 by root              #+#    #+#             */
/*   Updated: 2025/02/14 14:47:55 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, void* param, t_game *game)
{
	int i = 0;
	
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		ft_stop_music();
	}	
	if (mlx_is_key_down(mlx, MLX_KEY_UP)|| (mlx_is_key_down(mlx,MLX_KEY_W)))
		ft_up();
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx,MLX_KEY_S)))
		ft_down();
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx,MLX_KEY_A)))
		ft_left();
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || (mlx_is_key_down(mlx,MLX_KEY_D)))
		ft_right();
	if (mlx_is_key_down(mlx, MLX_KEY_R) || (mlx_is_key_down(mlx, MLX_KEY_KP_0)))
		transform(game);
}
void	ft_up(game)
{
	if(game-> + 1 != 1)
	{
		game->player->instances[0].y -= 5;
		game->move_count++; 
		ft_printf("Moves: %d\n", game->move_count);
	}
}


void	ft_down(game)
{
	if(game->map + 1 != 1)
	{
		player->instances[0].y += 5;
		game->move_count++;
		ft_printf("Moves: %d\n", game->move_count);
	}			
}
void	ft_left(game)
{
	if(game->map + 1 != 1)
	{
		player->instances[0].x -= 5;	
		game->move_count++;
		ft_printf("Moves: %d\n", game->move_count);
	}	
}
void	ft_right(game)
{
	if(game->map + 1 != 1)
	{
		player->instances[0].x += 5;	
		game->move_count++;
		ft_printf("Moves: %d\n", game->move_count);
	}	
}