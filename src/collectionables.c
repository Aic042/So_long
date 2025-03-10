/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectionables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:53:48 by root              #+#    #+#             */
/*   Updated: 2025/03/09 18:08:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect_count(t_game *game)
{
	int	total;
	int	y;
	int	x;

	total = 0;
	y = 0;
	while (game->map->map2d[y])
	{
		x = 0;
		while (game->map->map2d[y][x])
		{
			if (game->map->map2d[y][x] == 'C')
				total++;
			x++;
		}
		y++;
	}
	return (total);
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
		if (game->player->count_collect == game->total_collectibles)
		{
			ft_printf("You win! All coins collected.\n");
			ft_end_game(game);
		}
		else
			ft_printf("Collect all coins first! (%d/%d)\n", 
					  game->player->count_collect, game->total_collectibles);
	}
}

// Increment the collectible count
// Replace the collectible with a floor tile
// Update the display (if you have a collectible counter on the screen)
// // Check if all collectibles are collected
// if (game->player->count_collect == collect_count(game))
// {
//     game->textures->exit
// }