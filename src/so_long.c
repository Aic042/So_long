/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:55:37 by root              #+#    #+#             */
/*   Updated: 2025/02/20 09:26:13 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initialize game structure and related components
int	init_game(t_game *game)
{
	game->move_count = 0;
	game->count_collec = 0;
	game->player = malloc(sizeof(t_player));
	game->textures = malloc(sizeof(t_textures));
	game->window = malloc(sizeof(t_window));
	if (!game->player || !game->textures || !game->window)
		return (FALSE);
	game->window->mlx = mlx_init(game->map->columns * SIZE, game->map->rows * SIZE, "so_long", false);
	if (!(game->window->mlx))
		return (FALSE);
	load_textures(game);
	create_images(game);
	draw_map(game);
	mlx_key_hook(game->window->mlx, (mlx_keyfunc)handle_input, game);
	mlx_loop_hook(game->window->mlx, (mlx_loopfunc)render, game);
	mlx_loop(game->window->mlx);
	return (TRUE);
}

// Main function
int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf(Err_Mem), 1);
	if (argc != 2)
		return (ft_printf(Err_arg), ft_end_game(game), 1);
	ft_validate_file(argv[1]);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (ft_printf(Err_Mem), ft_end_game(game), 1);
	game->map->map = ft_read_map(argv[1]);
	if (!game->map->map)
		return (ft_end_game(game), 1);
	ft_validate_map(game);
	// ft_path_checker(game);
	if (init_game(game) == FALSE)
		return (ft_end_game(game), 1);
	ft_end_game(game);
	return (0);
}