/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:45:12 by root              #+#    #+#             */
/*   Updated: 2025/03/08 19:33:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_imgs(t_game *game)
{
    if (game->imgs)
    {
        if (game->imgs->wall)
            mlx_delete_image(game->mlx, game->imgs->wall);
        if (game->imgs->floor)
            mlx_delete_image(game->mlx, game->imgs->floor);
        if (game->imgs->player)
            mlx_delete_image(game->mlx, game->imgs->player);
        if (game->imgs->exit)
            mlx_delete_image(game->mlx, game->imgs->exit);
        if (game->imgs->collec)
            mlx_delete_image(game->mlx, game->imgs->collec);
        free(game->imgs);
        game->imgs = NULL;
    }
}

// Function to free textures
void	free_textures(t_game *game)
{
	if (game->textures)
	{
		if (game->textures->wall)
		{
			mlx_delete_texture(game->textures->wall);
			game->textures->wall = NULL;
		}
		if (game->textures->floor)
		{
			mlx_delete_texture(game->textures->floor);
			game->textures->floor = NULL;
		}
		if (game->textures->player)
		{
			mlx_delete_texture(game->textures->player);
			game->textures->player = NULL;
		}
		if (game->textures->exit)
		{
			mlx_delete_texture(game->textures->exit);
			game->textures->exit = NULL;
		}
		free(game->textures);
		game->textures = NULL;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		if (game->map->map2d)
		{
			while (game->map->map2d[i])
			{
				free(game->map->map2d[i]);
				game->map->map2d[i] = NULL;
				i++;
			}
			free(game->map->map2d);
			game->map->map2d = NULL;
		}
		free(game->map);
		game->map = NULL;
	}
}

// Function to free player
void	free_player(t_game *game)
{
	if (game->player)
	{
		free(game->player);
		game->player = NULL;
	}
}

// Main function that calls all the free functions
void ft_end_game(t_game *game)
{
	if (!game)
		return;
	free_imgs(game);
	free_textures(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_map(game);
	free_player(game);
	if (game->window)
		free(game->window);
	free(game);
	exit(0);
}
