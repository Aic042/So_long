/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:52:25 by root              #+#    #+#             */
/*   Updated: 2025/02/18 19:53:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to free textures
void free_textures(t_game *game) {
    if (game->textures) {
        if (game->textures->wall)
            mlx_delete_texture(game->textures->wall);
        if (game->textures->floor)
            mlx_delete_texture(game->textures->floor);
        if (game->textures->player)
            mlx_delete_texture(game->textures->player);
        if (game->textures->exit)
            mlx_delete_texture(game->textures->exit);
        free(game->textures);
    }
}

// Function to free map
void free_map(t_game *game) {
    if (game->map) {
        if (game->map->map) {
            int i = 0;
            while (game->map->map[i]) {
                free(game->map->map[i]);
                i++;
            }
            free(game->map->map);
        }
        free(game->map);
    }
}

// Function to free player
void free_player(t_game *game) {
    if (game->player) {
        free(game->player);
    }
}

// Function to terminate MLX and free window
void free_mlx_and_window(t_game *game) {
    if (game->window && game->window->mlx) {
        mlx_terminate(game->window->mlx);
        free(game->window);
    }
}

// Main function that calls all the free functions
void ft_end_game(t_game *game) {
    free_textures(game);
    free_map(game);
    free_player(game);
    free_mlx_and_window(game);
    free(game);
}
