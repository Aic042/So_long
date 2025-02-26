/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:45:12 by root              #+#    #+#             */
/*   Updated: 2025/02/26 10:45:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to free textures
void free_textures(t_game *game)
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

// Function to free map
void free_map(t_game *game) {
    if (game->map) {
        if (game->map->map2d) {
            int i = 0;
            while (game->map->map2d[i]) {
                free(game->map->map2d[i]);
                i++;
            }
            free(game->map->map2d);
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
