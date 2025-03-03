	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureandsh#t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:15:48 by root              #+#    #+#             */
/*   Updated: 2025/02/27 07:52:26 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_boot_imgs(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	game->textures->wall = mlx_load_png("../assets/wall.png");
	game->textures->floor = mlx_load_png("../assets/floor.png");
	game->textures->player = mlx_load_png("../assets/player.png");
	game->textures->exit = mlx_load_png("../assets/exit.png");
}

void	imgs_to_textures(t_game *game)
{
	game->imgs = ft_calloc(1, sizeof(t_imgs));
	game->imgs->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	game->imgs->floor = mlx_texture_to_image(game->mlx, game->textures->floor);
	game->imgs->player = mlx_texture_to_image(game->mlx, game->textures->player);
	game->imgs->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
}

void	render_chars(t_game *game, char	tile, int	x, int	y)
{
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->imgs->wall, x * Tile_Size, y * Tile_Size);
	else if (tile == 'C')
		mlx_image_to_window(game->mlx, game->imgs->collectible, x * Tile_Size, y * Tile_Size);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->imgs->exit, x * Tile_Size, y * Tile_Size);
	else if (tile == 'P')
		mlx_image_to_window(game->mlx, game->imgs->player, x * Tile_Size, y * Tile_Size);
	else
		mlx_image_to_window(game->mlx, game->imgs->floor, x * Tile_Size, y * Tile_Size);
}
void	draw_floor(t_game *game, t_imgs *image)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map2d[y])
	{
		x = 0;
		while (game->map->map2d[y][x])
		{
			mlx_image_to_window(game->mlx, image->floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	draw_floor(game, game->imgs);
	y = 0;
	while (game->map->map2d[y])
	{
		x = 0;
		while (game->map->map2d[y][x])
		{
			if (game->map->map2d[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->imgs->collectible, x * Tile_Size, y * Tile_Size);
			else if (game->map->map2d[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->imgs->exit, x * Tile_Size, y * Tile_Size);
			else if (game->map->map2d[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->imgs->player, x * Tile_Size, y * Tile_Size);
			else if (game->map->map2d[y][x] == '1')
				mlx_image_to_window(game->mlx, game->imgs->wall, x * Tile_Size, y * Tile_Size);
			x++;
		}
		y++;
	}
}
