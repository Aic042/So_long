/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:43:09 by root              #+#    #+#             */
/*   Updated: 2025/03/10 16:00:20 by aingunza         ###   ########.fr       */
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
	int	p_count;

	p_count = 0;
	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->columns)
		{
			if (game->map->map2d[y][x] == 'P')
			{
				game->player->x = x;
				game->player->y = y;
				p_count++;
			}
			x++;
		}
		y++;
	}
	if (p_count != 1)
		return (ft_printf("Error: Must have exactly one p1.\n"), 1);
	return (0);
}

// int	ft_file_validator_map(t_game *game)
// {
// 	find_initial_position(game);
// 	ft_flood_doer(game, game->player->y, game->player->x, game->map->map2d);
// 	ft_validate_accessible_cells(game);
// 	return (0);
// }
