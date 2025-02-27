/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:45:12 by root              #+#    #+#             */
/*   Updated: 2025/02/27 12:36:36 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to free textures
void	free_textures(t_game *game)
{
	if (game->textures)
	{
		if (game->textures->wall) {
			mlx_delete_texture(game->textures->wall);
			game->textures->wall = NULL;
		}
		if (game->textures->floor) {
			mlx_delete_texture(game->textures->floor);
			game->textures->floor = NULL;
		}
		if (game->textures->player) {
			mlx_delete_texture(game->textures->player);
			game->textures->player = NULL;
		}
		if (game->textures->exit) {
			mlx_delete_texture(game->textures->exit);
			game->textures->exit = NULL;
		}
		free(game->textures);
		game->textures = NULL;
	}
}

// Function to free player
void	free_player(t_game *game) {
	if (game->player) {
		free(game->player);
	}
}

// Main function that calls all the free functions
void	ft_end_game(t_game *game) {
	free_textures(game);
	free_map(game);
	free_player(game);
	free(game);
	exit(0);
}
