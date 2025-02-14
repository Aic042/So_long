/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:45 by root              #+#    #+#             */
/*   Updated: 2025/02/14 15:12:22 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_game *game)
{
	if(game->map + 1 != 1)
	{
		game->player->instances[0].y -= 5;
		game->player->move_count++; 
		ft_printf("Moves: %d\n", game->player->move_count);
	}
}


void ft_down(t_game *game)
{
	if(game->map + 1 != 1)
	{
		game->player->instances[0].y += 5;
		game->player->move_count++;
		ft_printf("Moves: %d\n", game->player->move_count);
	}			
}
void ft_left(t_game *game)
{
	if(game->map + 1 != 1)
	{
		game->player->instances[0].x -= 5;	
		game->player->move_count++;
		ft_printf("Moves: %d\n", game->player->move_count);
	}	
}
void ft_right(t_game *game)
{
	if(game->map + 1 != 1)
	{
		game->player->instances[0].x += 5;	
		game->player->move_count++;
		ft_printf("Moves: %d\n", game->player->move_count);
	}	
}

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
		ft_up(game);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx,MLX_KEY_S)))
		ft_down(game);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx,MLX_KEY_A)))
		ft_left(game);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || (mlx_is_key_down(mlx,MLX_KEY_D)))
		ft_right(game);
	if (mlx_is_key_down(mlx, MLX_KEY_R) || (mlx_is_key_down(mlx, MLX_KEY_KP_0)))
		transform(game);
}