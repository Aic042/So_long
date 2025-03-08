/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:45 by root              #+#    #+#             */
/*   Updated: 2025/03/08 12:37:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_game *game)
{
    if (game->map->map2d[game->player->y - 1][game->player->x] != '1')
    {
        char new_tile = game->map->map2d[game->player->y - 1][game->player->x];
        game->map->map2d[game->player->y][game->player->x] = '0'; // Clear old position
        game->player->y -= 1;
        game->player->move_count++;
        coin_collecter(game); // Check new position before overwriting
        if (new_tile != 'E') // Only overwrite if not exit
            game->map->map2d[game->player->y][game->player->x] = 'P';
        draw_map(game); // Always redraw
        ft_printf("Moves: %d\n", game->player->move_count);
    }
}

void	ft_down(t_game *game)
{
    if (game->map->map2d[game->player->y + 1][game->player->x] != '1')
    {
        char new_tile = game->map->map2d[game->player->y + 1][game->player->x];
        game->map->map2d[game->player->y][game->player->x] = '0';
        game->player->y += 1;
        game->player->move_count++;
        coin_collecter(game);
        if (new_tile != 'E')
            game->map->map2d[game->player->y][game->player->x] = 'P';
        draw_map(game);
        ft_printf("Moves: %d\n", game->player->move_count);
    }
}

void	ft_left(t_game *game)
{
    if (game->map->map2d[game->player->y][game->player->x - 1] != '1')
    {
        char new_tile = game->map->map2d[game->player->y][game->player->x - 1];
        game->map->map2d[game->player->y][game->player->x] = '0';
        game->player->x -= 1;
        game->player->move_count++;
        coin_collecter(game);
        if (new_tile != 'E')
            game->map->map2d[game->player->y][game->player->x] = 'P';
        draw_map(game);
        ft_printf("Moves: %d\n", game->player->move_count);
    }
}

void	ft_right(t_game *game)
{
    if (game->map->map2d[game->player->y][game->player->x + 1] != '1')
    {
        char new_tile = game->map->map2d[game->player->y][game->player->x + 1];
        game->map->map2d[game->player->y][game->player->x] = '0';
        game->player->x += 1;
        game->player->move_count++;
        coin_collecter(game);
        if (new_tile != 'E')
            game->map->map2d[game->player->y][game->player->x] = 'P';
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

//Z1196572W