/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:57:58 by root              #+#    #+#             */
/*   Updated: 2025/03/03 19:56:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	    ft_count_strings(char	**map)
// {
//         int	    count;
//         int	    i;

//         count = 0;
//         i = 0;
//         while (map[i] != 0)
//         {
//                 count++;
//                 i++;
//         }
//         return (count);
// }

void	ft_validate_2dmap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->columns)
		{
			if (x == 0 && game->map->map2d[y][x] != '1')
				ft_printf(ERR_MAP, 1);
			if (y == 0 && game->map->map2d[y][x] != '1')
				ft_printf(ERR_MAP, 1);
			if (x == game->map->columns - 1 && game->map->map2d[y][x] != '1')
				ft_printf(ERR_MAP, 1);
			if (y == game->map->rows - 1 && game->map->map2d[y][x] != '1')
				ft_printf(ERR_MAP, 1);
			x++;
		}
		y++;
	}
}

void	ft_flood_doer(t_game *game, int y, int x)
{
	game->map->columns = 0;
	game->map->rows = 0;
	if (!(x < 1 || y < 1 || x >= game->map->columns || y >= game->map->rows
			|| game->map->map2d[y][x] == '1' || game->map->map2d[y][x] == 'X'))
	{
		game->map->map2d[y][x] = 'X';
		ft_flood_doer(game, y + 1, x);
		ft_flood_doer(game, y - 1, x);
		ft_flood_doer(game, y, x + 1);
		ft_flood_doer(game, y, x - 1);
	}
}
