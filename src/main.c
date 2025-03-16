/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:27:37 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/16 09:58:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	ft_printf("Initial collectibles: %d\n", game->total_colec);
	game->player->move_count = 0;
	game->player->count_collec = 0;
	game->window = malloc(sizeof(t_window));
	if (!game->window)
		return (1);
	if (game->total_colec == 0)
		return (ft_printf(ERR_MAP), ft_end_game(game), 1);
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", false);
	if (!game->mlx)
		return (1);
	ft_boot_img(game);
	img_to_textures(game);
	draw_map(game);
	mlx_key_hook(game->mlx, &ft_my_hook, game);
	mlx_loop(game->mlx);
	return (0);
}

void	null_settlers(t_game *game)
{
	game->img = NULL;
	game->map = NULL;
	game->player = NULL;
	game->textures = NULL;
	game->window = NULL;
	game->mlx = NULL;
	game->temp_collec = 0;
}

int	dealbreakers(t_game *game)
{
	if (!are_row_lengths_consistent(game->map->map2d, game->map->rows))
		return (ft_printf("Error: Map row lengths. \n"), ft_end_game(game), 1);
	if (wall_checker(game) != 0 || ft_file_validator_map(game) != 0)
		return (ft_end_game(game), 1);
	if (init_game(game) != 0)
		return (ft_end_game(game), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf(ERR_ARG), 1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf(ERR_MEM), 1);
	null_settlers(game);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (ft_printf(ERR_MEM), ft_end_game(game), 1);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return (ft_printf(ERR_MEM), ft_end_game(game), 1);
	game->map->map2d = ft_read_map(argv[1]);
	if (!game->map->map2d)
		return (ft_printf("map2d is NULL\n"), ft_end_game(game), 1);
	map_size(game, game->map->map2d);
	game->total_colec = collect_count(game);
	dealbreakers(game);
	ft_end_game(game);
	return (0);
}
