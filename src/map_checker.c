/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:28:11 by root              #+#    #+#             */
/*   Updated: 2025/03/10 14:36:29 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_empty(char **map)
{
	if (map == NULL)
		return (1);
	else
		return (0);
}

int	ft_validate_walls(t_game *game)
{
	int	y;

	y = 0;
	if (!game || !game->map || !game->map->map2d)
	{
		ft_printf("Error: Invalid game or map data.\n");
		exit(1);
	}
	while (y < game->map->rows)
	{
		if ((y == 0 || y == game->map->rows - 1)
			&& !is_row_surrounded_by_walls(game->map->map2d[y]))
		{
			ft_printf("Error: El mapa no está rodeado de muros.\n");
			exit(1);
		}
		if (game->map->map2d[y][0] != '1'
			|| game->map->map2d[y][game->map->columns - 1] != '1')
		{
			ft_printf("Error: El mapa no está rodeado de muros.\n");
			exit(1);
		}
		y++;
	}
	return (0);
}

int	validate_map(char **map, t_game *game)
{
	if (ft_map_empty(map) == 0)
		return (ft_printf(ERR_MAP), FALSE);
	if (ft_validate_walls(game) == FALSE)
		return (ft_printf(E_WALLS), FALSE);
	return (TRUE);
}
