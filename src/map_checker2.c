/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:43:09 by root              #+#    #+#             */
/*   Updated: 2025/03/06 12:08:09 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Check_Counts
int	ft_check_counts(int E, int P, int C)
{
	if (E != 1 || P != 1 || C < 1)
	{
		printf("map couldn't be loaded 😔\n");
		return (1);
	}
	else
	{
		printf("Map loaded successfully 🥳\n");
		return (0);
	}
}

int	find_initial_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map2d[y])
	{
		x = 0;
		while (game->map->map2d[y][x])
		{
			if (game->map->map2d[y][x] == 'P')
			{
				game->player->x = x;
				game->player->y = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_validate_accessible_cells(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map2d[y])
	{
		x = 0;
		while (game->map->map2d[y][x])
		{
			if (game->map->map2d[y][x] != '0' && game->map->map2d[y][x] != '1' &&
				game->map->map2d[y][x] != 'C' && game->map->map2d[y][x] != 'E' &&
				game->map->map2d[y][x] != 'P')
			{
				ft_printf("Error: Invalid character '%c' at [%d][%d]\n", game->map->map2d[y][x], y, x);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

// int	ft_file_validator_map(t_game *game)
// {
// 	find_initial_position(game);
// 	ft_flood_doer(game, game->player->y, game->player->x, game->map->map2d);
// 	ft_validate_accessible_cells(game);
// 	return (0);
// }
