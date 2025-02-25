/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:45 by root              #+#    #+#             */
/*   Updated: 2025/02/25 12:40:46 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_game *game)
{
	if (game->map->map2d[game->player->y - 1][game->player->x] != '1')
	{
		game->player->y -= 1;
		game->player->move_count++; 
		ft_printf("Moves: %d\n", game->player->move_count);
	}
}

void ft_down(t_game *game)
{
	if (game->map->map2d[game->player->y + 1][game->player->x] != '1')
	{
		game->player->y += 1;
		game->player->move_count++;
		ft_printf("Moves: %d\n", game->player->move_count);
	}			
}

void ft_left(t_game *game)
{
	if (game->map->map2d[game->player->y][game->player->x - 1] != '1')
	{
		game->player->x -= 1;
		game->player->move_count++;
		ft_printf("Moves: %d\n", game->player->move_count);
	}	
}

void ft_right(t_game *game)
{
	if (game->map->map2d[game->player->y][game->player->x + 1] != '1')
	{
		game->player->x += 1;
		game->player->move_count++;
		ft_printf("Moves: %d\n", game->player->move_count);
	}	
}

void ft_my_hook(mlx_key_data_t keydata, void* param)
{	
	t_game *game = (t_game *)param;
	mlx_t* mlx = game->window->mlx;
	(void)keydata;
	
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		ft_end_game(game);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_UP)|| (mlx_is_key_down(mlx,MLX_KEY_W)))
	ft_up(game);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx,MLX_KEY_S)))
	ft_down(game);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx,MLX_KEY_A)))
	ft_left(game);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || (mlx_is_key_down(mlx,MLX_KEY_D)))
	ft_right(game);
}

// ft_stop_music();

// if (mlx_is_key_down(mlx, MLX_KEY_R) || (mlx_is_key_down(mlx, MLX_KEY_KP_0)))
// 	transform(game);