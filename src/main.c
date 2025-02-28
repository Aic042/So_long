/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:27:37 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/28 19:13:20 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_loop_wrapper(void* param)
{
    t_game *game = (t_game *)param;
    mlx_loop(game->mlx);
}

int init_game(t_game *game)
{
    game->textures = malloc(sizeof(t_textures));
    if (!game->textures)
        return (1);
    // Initialize texture pointers to NULL
    game->textures->wall = NULL;
    game->textures->floor = NULL;
    game->textures->player = NULL;
    game->textures->exit = NULL;

    game->window = malloc(sizeof(t_window));
    if (!game->window)
    {
        free(game->textures);  // Clean up textures on failure
        return (1);
    }

    if (!game->player)  // This check is redundant since main ensures game->player is allocated
        return (1);

    game->player->move_count = 0;
    game->player->count_collect = 0;

    game->mlx = mlx_init(game->map->columns * Tile_Size, game->map->rows * Tile_Size, "so_long", false);
    if (!game->mlx)
    {
        free(game->window);
        free(game->textures);
        return (1);
    }

    ft_boot_imgs(game);  // Assume this loads images
    imgs_to_textures(game);  // Assume this sets game->textures->wall, etc.
    draw_map(game);
    mlx_key_hook(game->mlx, &ft_my_hook, game);
    mlx_loop_hook(game->mlx, mlx_loop_wrapper, game);
    mlx_loop(game->mlx);
    return 0;
}

int main(int argc, char **argv)
{
    t_game *game;

    if (argc != 2)
        return (ft_printf(Err_arg), 1);

    game = malloc(sizeof(t_game));
    if (!game)
        return (ft_printf(Err_Mem), 1);

    // Initialize all pointers to NULL
    game->map = NULL;
    game->player = NULL;
    game->textures = NULL;
    game->window = NULL;
    game->mlx = NULL;  // Add this for MLX cleanup

    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (ft_printf(Err_Mem), ft_end_game(game), 1);

    game->player = malloc(sizeof(t_player));
    if (!game->player)
        return (ft_printf(Err_Mem), ft_end_game(game), 1);

    game->map->map2d = ft_read_map(argv[1]);
    if (!game->map->map2d)
    {
        ft_printf("map2d is NULL\n");
        return (ft_end_game(game), 1);
    }

    if (ft_file_validator_map(game) != 0)
        return (ft_end_game(game), 1);

    if (init_game(game) == FALSE)
        return (ft_end_game(game), 1);

    ft_end_game(game);
    return 0;
}

