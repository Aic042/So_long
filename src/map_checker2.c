/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:43:09 by root              #+#    #+#             */
/*   Updated: 2025/03/17 23:58:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Check_Exits

int	has_one_exit(t_game *game)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->columns)
		{
			if (game->map->map2d[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	has_no_empty_lines(t_game *game)
{
	int		y;
	char	*row;

	y = 0;
	while (y < game->map->rows)
	{
		row = game->map->map2d[y];
		if (!row || row[0] == '\n')
			return (0);
		y++;
	}
	return (1);
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
