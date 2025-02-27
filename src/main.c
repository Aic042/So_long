/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:27:37 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/27 09:04:22 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mlx_loop_wrapper(void* param)
{
    t_game *game = (t_game *)param;
    mlx_loop(game->window->mlx);
}

int init_game(t_game *game)
{
    game->textures = ft_calloc(1, sizeof(t_textures));
    if (!game->textures)
        return (1);
    game->window = malloc(sizeof(t_window));
    if (!game->player || !game->textures || !game->window)
        return (1);
    game->player->move_count = 0;
    game->player->count_collect = 0;
    game->window->mlx = mlx_init(game->map->columns * Tile_Size, game->map->rows * Tile_Size, "so_long", false);
    if (!(game->window->mlx))
        return (1);
    ft_boot_images(game);
    images_to_textures(game);
    draw_map(game);
    mlx_key_hook(game->window->mlx, &ft_my_hook, game);
    mlx_loop_hook(game->window->mlx, mlx_loop_wrapper, game);
    mlx_loop(game->window->mlx);
    return 0;
}

// main.c
int main(int argc, char **argv) {
    t_game *game = ft_calloc(1, sizeof(t_game));
    if (!game)
        return (ft_printf(Err_Mem), 1);

    game->map = ft_calloc(1, sizeof(t_map));
    if (!game->map)
        return (ft_printf(Err_Mem), ft_end_game(game), 1);

    game->player = ft_calloc(1, sizeof(t_player));
    if (!game->player)
        return (ft_printf(Err_Mem), ft_end_game(game), 1);

    if (argc != 2)
        return (ft_printf(Err_arg), ft_end_game(game), 1);

    // Step 1: Read the map FIRST
    game->map->map2d = ft_read_map(argv[1]);
    if (!game->map->map2d) {
        ft_printf("Error: Failed to read map.\n");
        return (ft_end_game(game), 1);
    }

    // Step 2: *Then* validate the file format (.ber)
    ft_validate_file(argv[1]); // Validate file extension *before* reading the map
    if (ft_map_empty(game))
        return (ft_printf("Error: Map is empty.\n"), ft_end_game(game), 1);

    // Step 3: *Then* find the initial player position (needs a valid map)
    find_initial_position(game);

    // Step 4: *Then* validate the map's contents (needs player position)
    if (ft_file_validator_map(game) != 0) {
        ft_end_game(game);
        return 1;
    }

    //Step 5: Init game.
    if (init_game(game) == FALSE)
        return (ft_end_game(game), 1);
    ft_end_game(game);
    return 0;
}
