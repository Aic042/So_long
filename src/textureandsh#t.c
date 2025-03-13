/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureandsh#t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:15:48 by root              #+#    #+#             */
/*   Updated: 2025/03/10 17:48:31 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_boot_img(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
	{
		ft_printf("Error: Failed to allocate textures\n");
		exit(1);
	}
	game->textures->wall = mlx_load_png("./assets/wall2.png");
	game->textures->floor = mlx_load_png("./assets/floor2.png");
	game->textures->p1 = mlx_load_png("./assets/player2.png");
	game->textures->exit = mlx_load_png("./assets/exit.png");
	game->textures->coin = mlx_load_png("./assets/collec2.png");
	if (!game->textures->wall || !game->textures->floor
		|| !game->textures->p1 || !game->textures->exit
		|| !game->textures->coin)
	{
		ft_printf("Error: Failed to load one or more PNG files\n");
		free_textures(game);
		exit(1);
	}
}

void	img_to_textures(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	if (!game->img)
	{
		ft_printf("Error: Failed to allocate images\n");
		exit(1);
	}
	game->img->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	game->img->floor = mlx_texture_to_image(game->mlx, game->textures->floor);
	game->img->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
	game->img->coin = mlx_texture_to_image(game->mlx, game->textures->coin);
	game->img->p1 = mlx_texture_to_image(game->mlx, game->textures->p1);
	free_textures(game);
}

//CHECK floor
void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map2d[y])
	{
		x = 0;
		while (game->map->map2d[y][x])
		{
			mlx_image_to_window(game->mlx, game->img->floor, x * T, y * T);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	draw_floor(game);
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->columns)
		{
			if (game->map->map2d[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img->coin, x * T, y * T);
			else if (game->map->map2d[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img->exit, x * T, y * T);
			else if (game->map->map2d[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img->p1, x * T, y * T);
			else if (game->map->map2d[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img->wall, x * T, y * T);
			x++;
		}
		y++;
	}
}
