/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectionables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:53:48 by root              #+#    #+#             */
/*   Updated: 2025/03/10 16:05:37 by aingunza         ###   ########.fr       */
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
		game->map->map2d[game->player->y][game->player->x] = '0';
		ft_printf("Collected a coin! Total: %d\n", game->player->count_collect);
	}
	else if (game->map->map2d[game->player->y][game->player->x] == 'E')
	{
		if (game->player->count_collect == game->total_collectibles)
			ft_printf("You win! All coins collected.\n");
		else
			ft_printf("You lose! Not all coins collected.\n");
		ft_end_game(game);
	}
}
