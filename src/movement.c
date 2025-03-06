/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:45 by root              #+#    #+#             */
/*   Updated: 2025/03/06 15:00:07 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_up(t_game *game)
{
	if (game->map->map2d[game->player->y - 1][game->player->x] != '1')
	{
		game->map->map2d[game->player->y][game->player->x] = '0'; // Clear old position
		game->player->y -= 1;
		game->map->map2d[game->player->y][game->player->x] = 'P'; // Set new position
		game->player->move_count++;
		coin_collecter(game); // Handle collectibles/exit
		draw_map(game);
		ft_printf("Moves: %d\n", game->player->move_count);
	}
}

void ft_down(t_game *game)
{
	if (game->map->map2d[game->player->y + 1][game->player->x] != '1')
	{
		game->map->map2d[game->player->y][game->player->x] = '0';
		game->player->y += 1;
		game->map->map2d[game->player->y][game->player->x] = 'P';
		game->player->move_count++;
		coin_collecter(game);
		draw_map(game);
		ft_printf("Moves: %d\n", game->player->move_count);
	}
}

void ft_left(t_game *game)
{
	if (game->map->map2d[game->player->y][game->player->x - 1] != '1')
	{
		game->map->map2d[game->player->y][game->player->x] = '0';
		game->player->x -= 1;
		game->map->map2d[game->player->y][game->player->x] = 'P';
		game->player->move_count++;
		coin_collecter(game);
		draw_map(game);
		ft_printf("Moves: %d\n", game->player->move_count);
	}
}

void ft_right(t_game *game)
{
	if (game->map->map2d[game->player->y][game->player->x + 1] != '1')
	{
		game->map->map2d[game->player->y][game->player->x] = '0';
		game->player->x += 1;
		game->map->map2d[game->player->y][game->player->x] = 'P';
		game->player->move_count++;
		coin_collecter(game);
		draw_map(game);
		ft_printf("Moves: %d\n", game->player->move_count);
	}
}

void	ft_my_hook(mlx_key_data_t keydata, void	*param)
{
	t_game	*game;
	mlx_t	*mlx;

	game = (t_game *)param;
	mlx = game->mlx;
	(void)keydata;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		ft_end_game(game);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_UP)
		|| (mlx_is_key_down(mlx, MLX_KEY_W)))
		ft_up(game);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN)
		|| (mlx_is_key_down(mlx, MLX_KEY_S)))
		ft_down(game);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT)
		|| (mlx_is_key_down(mlx, MLX_KEY_A)))
		ft_left(game);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)
		|| (mlx_is_key_down(mlx, MLX_KEY_D)))
		ft_right(game);
}

// ft_stop_music();

// if (mlx_is_key_down(mlx, MLX_KEY_R) || (mlx_is_key_down(mlx, MLX_KEY_KP_0)))
// 	transform(game);