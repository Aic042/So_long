/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureandsh#t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:15:48 by root              #+#    #+#             */
/*   Updated: 2025/02/26 09:34:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_boot_images(t_game *game)
{
    game->textures = ft_calloc(1, sizeof(t_textures));
    game->images = ft_calloc(1, sizeof(t_images));
    game->images->wall = mlx_texture_to_image(game->window->mlx, game->textures->wall);
    game->images->floor = mlx_texture_to_image(game->window->mlx, game->textures->floor);
    game->images->player = mlx_texture_to_image(game->window->mlx, game->textures->player);
    game->images->exit = mlx_texture_to_image(game->window->mlx, game->textures->exit);
    
}

void	images_to_textures(t_game *game)
{
    game->images = ft_calloc(1, sizeof(t_images));
	game->images->wall = mlx_texture_to_image(game->window->mlx, game->textures->wall);
	game->images->floor = mlx_texture_to_image(game->window->mlx, game->textures->floor);
	game->images->player = mlx_texture_to_image(game->window->mlx, game->textures->player);
	game->images->exit = mlx_texture_to_image(game->window->mlx, game->textures->exit);

	// Clean up old textures after converting to images
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->floor);
	mlx_delete_texture(game->textures->player);
	mlx_delete_texture(game->textures->exit);

    if (game->textures->wall)
        mlx_delete_texture(game->textures->wall);
    if (game->textures->floor)
        mlx_delete_texture(game->textures->floor);
    if (game->textures->player)
        mlx_delete_texture(game->textures->player);
    if (game->textures->exit)
        mlx_delete_texture(game->textures->exit);
}

void render_tile(t_game *game, char tile, int x, int y)
{
    if (tile == '1')
        mlx_image_to_window(game->window->mlx, game->images->wall, x * Tile_Size, y * Tile_Size);
    else if (tile == 'C')
        mlx_image_to_window(game->window->mlx, game->images->collectible, x * Tile_Size, y * Tile_Size);
    else if (tile == 'E')
        mlx_image_to_window(game->window->mlx, game->images->exit, x * Tile_Size, y * Tile_Size);
    else if (tile == 'P')
        mlx_image_to_window(game->window->mlx, game->images->player, x * Tile_Size, y * Tile_Size);
    else
        mlx_image_to_window(game->window->mlx, game->images->floor, x * Tile_Size, y * Tile_Size);
}
void draw_floor(t_game *game, t_images *image)
{
    int x;
    int y;

    y = 0;
    while (game->map->map2d[y])
    {
        x = 0;
        while (game->map->map2d[y][x])
        {
            mlx_image_to_window(game->window->mlx, image->floor, x * Tile_Size, y * Tile_Size);
            x++;
        }
        y++;
    }
}

void draw_map(t_game *game)
{
    int x;
    int y;

    draw_floor(game, game->images);
    y = 0;
    while (game->map->map2d[y])
    {
        x = 0;
        while (game->map->map2d[y][x])
        {
            if (game->map->map2d[y][x] == 'C')
                mlx_image_to_window(game->window->mlx, game->images->collectible, x * Tile_Size, y * Tile_Size);
            else if (game->map->map2d[y][x] == 'E')
                mlx_image_to_window(game->window->mlx, game->images->exit, x * Tile_Size, y * Tile_Size);
            else if (game->map->map2d[y][x] == 'P')
                mlx_image_to_window(game->window->mlx, game->images->player, x * Tile_Size, y * Tile_Size);
            else if (game->map->map2d[y][x] == '1')
                mlx_image_to_window(game->window->mlx, game->images->wall, x * Tile_Size, y * Tile_Size);
            x++;
        }
        y++;
    }
}