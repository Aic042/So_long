/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:45:12 by root              #+#    #+#             */
/*   Updated: 2025/03/10 16:00:57 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_game *game)
{
	if (game->img)
	{
		if (game->img->wall)
			mlx_delete_image(game->mlx, game->img->wall);
		if (game->img->floor)
			mlx_delete_image(game->mlx, game->img->floor);
		if (game->img->p1)
			mlx_delete_image(game->mlx, game->img->p1);
		if (game->img->exit)
			mlx_delete_image(game->mlx, game->img->exit);
		if (game->img->coin)
			mlx_delete_image(game->mlx, game->img->coin);
		free(game->img);
		game->img = NULL;
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
		if (game->textures->p1)
		{
			mlx_delete_texture(game->textures->p1);
			game->textures->p1 = NULL;
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

// Function to free p1
void	free_player(t_game *game)
{
	if (game->player)
	{
		free(game->player);
		game->player = NULL;
	}
}

// Main function that calls all the free functions
void	ft_end_game(t_game *game)
{
	free_img(game);
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
