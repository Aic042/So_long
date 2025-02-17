/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truemain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:03:01 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/17 12:25:32 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv, t_game *game)
{
    t_game game;

    if (argc != 2)
    {
        ft_printf("Error: Debes proporcionar un mapa .ber.\n");
        return (1);
    }
    ft_initialize_variables(&game);
    ft_read_map(argv[1]);
    ft_validate_walls(&game);
    game->window->mlx = mlx_init(game->screen_x, game->screen_y, "so_long", false);
    if (!game->window->mlx)
        return (1);
    ft_boot_textures(&game);
    ft_init_player(&game);
    mlx_key_hook(game->window->mlx, ft_move_player, &game);

    // Loop de eventos
    mlx_loop(game->window->mlx);

    return (0);
}
