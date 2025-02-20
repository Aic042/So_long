/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:45 by root              #+#    #+#             */
/*   Updated: 2025/02/20 11:09:26 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_up(t_game *game)
{
	if (game->map->map2d[game->player->y + 1][game->player->x] != '1')
	{
		game->player->y += 5;
		game->player->move_count++; 
		ft_printf("Moves: %d\n", game->player->move_count);
	}
}


static void ft_down(t_game *game)
{
	if (game->map->map2d[game->player->y - 1][game->player->x] != '1')
	{
		game->player->y -= 5;
		game->player->move_count++;
		ft_printf("Moves: %d\n", game->player->move_count);
	}			
}
static void ft_left(t_game *game)
{
	if (game->map->map2d[game->player->y - 1][game->player->x] != '1')
	{
		game->player->x -= 5;
		game->player->move_count++;
		ft_printf("Moves: %d\n", game->player->move_count);
	}	
}

//terminar los if
static void ft_right(t_game *game)
{
	if (game->map->map2d[game->player->y - 1][game->player->x] != '1')
	{
		game->player->x += 5;
		game->player->move_count++;
		ft_printf("Moves: %d\n", game->player->move_count);
	}	
}

void ft_hook(mlx_key_data_t keydata, void* param, t_game *game)
{	
	mlx_t* mlx = param;

	(void)keydata;
    (void)param;
	
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		// ft_stop_music();
	}	
	if (mlx_is_key_down(mlx, MLX_KEY_UP)|| (mlx_is_key_down(mlx,MLX_KEY_W)))
		ft_up(game);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx,MLX_KEY_S)))
		ft_down(game);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx,MLX_KEY_A)))
		ft_left(game);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || (mlx_is_key_down(mlx,MLX_KEY_D)))
		ft_right(game);
	// if (mlx_is_key_down(mlx, MLX_KEY_R) || (mlx_is_key_down(mlx, MLX_KEY_KP_0)))
	// 	transform(game);
}