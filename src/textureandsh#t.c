/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureandsh#t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:15:48 by root              #+#    #+#             */
/*   Updated: 2025/03/04 16:48:54 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_boot_imgs(t_game *game)
{
    game->textures = ft_calloc(1, sizeof(t_textures));
    if (!game->textures)
    {
        ft_printf("Error: Failed to allocate textures\n");
        exit(1);
    }
    game->textures->wall = mlx_load_png("../assets/wall.png");
    game->textures->floor = mlx_load_png("../assets/floor.png");
    game->textures->player = mlx_load_png("../assets/player.png");
    game->textures->exit = mlx_load_png("../assets/exit.png");

    if (!game->textures->wall || !game->textures->floor ||
        !game->textures->player || !game->textures->exit)
    {
        ft_printf("Error: Failed to load one or more PNG files\n");
        free_textures(game);
        exit(1);
    }
}

void	imgs_to_textures(t_game *game)
{
	if (!game->imgs)
    {
        ft_printf("Error: Failed to allocate images\n");
        exit(1);
    }
	game->imgs = ft_calloc(1, sizeof(t_imgs));
	game->imgs->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	game->imgs->floor = mlx_texture_to_image(game->mlx, game->textures->floor);
	game->imgs->player = mlx_texture_to_image(game->mlx, game->textures->player);
	game->imgs->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
	free_textures(game);
}

void	render_chars(t_game *game, char	tile, int	x, int	y)
{
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->imgs->wall, x * T_SI, y * T_SI);
	else if (tile == 'C')
		mlx_image_to_window(game->mlx, game->imgs->collectible, x * T_SI, y * T_SI);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->imgs->exit, x * T_SI, y * T_SI);
	else if (tile == 'P')
		mlx_image_to_window(game->mlx, game->imgs->player, x * T_SI, y * T_SI);
	else
		mlx_image_to_window(game->mlx, game->imgs->floor, x * T_SI, y * T_SI);
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
				mlx_image_to_window(game->mlx, game->imgs->collectible, x * T_SI, y * T_SI);
			else if (game->map->map2d[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->imgs->exit, x * T_SI, y * T_SI);
			else if (game->map->map2d[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->imgs->player, x * T_SI, y * T_SI);
			else if (game->map->map2d[y][x] == '1')
				mlx_image_to_window(game->mlx, game->imgs->wall, x * T_SI, y * T_SI);
			x++;
		}
		y++;
	}
}
