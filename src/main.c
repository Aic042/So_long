/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:27:37 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/04 11:05:22 by aingunza         ###   ########.fr       */
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
    game->textures->wall = NULL;
    game->textures->floor = NULL;
    game->textures->player = NULL;
    game->textures->exit = NULL;

    game->window = malloc(sizeof(t_window));
    if (!game->window)
        return (1);

    if (!game->player)
        return (1);

    game->player->move_count = 0;
    game->player->count_collect = 0;
    game->mlx = mlx_init(game->map_width * T_SI, game->map_height * T_SI, "so_long", false);
    if (!game->mlx)
        return (1);

    ft_boot_imgs(game);
    imgs_to_textures(game);
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
        return (ft_printf(ERR_ARG), 1);

    game = malloc(sizeof(t_game));
    if (!game)
        return (ft_printf(ERR_MEM), 1);

    // Initialize all pointers to NULL
    game->map = NULL;
    game->player = NULL;
    game->textures = NULL;
    game->window = NULL;
    game->mlx = NULL;  // Add this for MLX cleanup

    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (ft_printf(ERR_MEM), ft_end_game(game), 1);

    game->player = malloc(sizeof(t_player));
    if (!game->player)
        return (ft_printf(ERR_MEM), ft_end_game(game), 1);

    game->map->map2d = ft_read_map(argv[1]);
    if (!game->map->map2d)
    {
        ft_printf("map2d is NULL\n");
        ft_end_game(game);
        return (1);
    }
    map_size(game, game->map->map2d);  // Set rows and columns

    if (ft_file_validator_map(game) != 0)
        return (ft_end_game(game), 1);

    if (init_game(game) == FALSE)
        return (ft_end_game(game), 1);

    ft_end_game(game);
    return 0;
}
