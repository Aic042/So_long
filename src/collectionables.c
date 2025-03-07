/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectionables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:53:48 by root              #+#    #+#             */
/*   Updated: 2025/03/07 12:57:34 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect_count(t_game *game)
{
    int total = 0;
    int y = 0;
    while (game->map->map2d[y])
    {
        int x = 0;
        while (game->map->map2d[y][x])
        {
            if (game->map->map2d[y][x] == 'C')
                total++;
            x++;
        }
        y++;
    }
    return total;
}

void	coin_collecter(t_game *game)
{
	if (game->map->map2d[game->player->y][game->player->x] == 'C')
    {
        game->player->count_collect++;
        game->map->map2d[game->player->y][game->player->x] = 'P';
        ft_printf("Collected a coin! Total: %d\n", game->player->count_collect);
    }
    else if (game->map->map2d[game->player->y][game->player->x] == 'E')
    {
        if (game->player->count_collect == collect_count(game))
        {
            ft_printf("You win! All coins collected.\n");
            ft_end_game(game);
        }
    }
}

// Increment the collec count
// Replace the collec with a floor tile
// Update the display (if you have a collec counter on the screen)
// // Check if all collecs are collected
// if (game->player->count_collect == collect_count(game))
// {
//     game->textures->exit
// }