/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:27:37 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/28 15:11:44 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_loop_wrapper(void* param)
{
    t_game *game = (t_game *)param;
    mlx_loop(game->mlx);
}

int	init_game(t_game *game)
{
    game->textures = malloc(sizeof(t_textures));
    game->window = malloc(sizeof(t_window));
    if (!game->player || !game->textures || !game->window)
        return (1);
    game->player->move_count = 0;
    game->player->count_collect = 0;
    game->mlx = mlx_init(game->map->columns * Tile_Size, game->map->rows * Tile_Size, "so_long", false);
    if (!(game->mlx))
        return (1);
    ft_boot_imgs(game);
    imgs_to_textures(game);
    draw_map(game);
    mlx_key_hook(game->mlx, &ft_my_hook, game);
    mlx_loop_hook(game->mlx, mlx_loop_wrapper, game);
    mlx_loop(game->mlx);
    return 0;
}

int	main(int	argc, char	**argv)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (argc != 2)
        return (ft_printf(Err_arg), ft_end_game(game), 1);
    if (!game)
        return (ft_printf(Err_Mem), 1);
    validate_map(game->map->map2d);
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (ft_printf(Err_Mem), ft_end_game(game), 1);
    game->player = malloc(sizeof(t_player));
    if(!game->player)
        return (ft_printf(Err_Mem), ft_end_game(game), 1);
    game->map->map2d = ft_read_map(argv[1]);
    if (!game->map->map2d){
        ft_printf("map2d is NULL\n");
        return (ft_end_game(game), 1);
    }
    if (ft_file_validator_map(game) != 0){
        ft_end_game(game);
        return 1;
    }
    if (!game->map->map2d)
        return (ft_end_game(game), 1);
    if (init_game(game) == FALSE)
        return (ft_end_game(game), 1);
    ft_end_game(game);
    return 0;
}

