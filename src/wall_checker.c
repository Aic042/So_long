/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:33:57 by root              #+#    #+#             */
/*   Updated: 2025/03/08 19:01:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 int is_row_surrounded_by_walls(char	*row)
 {
	 int	len;

	 if (!row)
		 return (0);
	 len = ft_strlen(row);
	 if (row[0] != '1' || row[len - 1] != '1')
		 return (0);
	 return (1);
 }

int are_row_lengths_consistent(char **map, int rows)
{
    int     i;
    size_t  len;

    if (!map || rows <= 0)
        return (0);
    len = ft_strlen(map[0]);
    i = 1;
    while (i < rows)
    {
        if (ft_strlen(map[i]) != len)
            return (0);
        i++;
    }
    return (1);
}

int	map_corners(char	**map, int	rows)
{
	int	cols;

	if (!map || rows <= 0)
		return (0);
	cols = ft_strlen(map[0]);
	if (map[0][0] != '1' || map[0][cols - 1] != '1' ||
		map[rows - 1][0] != '1' || map[rows - 1][cols - 1] != '1')
	{
		return (0);
	}
	return (1);
}

int is_row_all_walls(char *row)
{
    int i;

    if (!row)
        return (0);
    i = 0;
    while (row[i])
    {
        if (row[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

int		Wall_checker(t_game *game)
{
    int y;

    if (!game || !game->map || !game->map->map2d)
        return (ft_printf("Error: Invalid game or map data.\n"), 1);
    y = 0;
    while (y < game->map->rows)
    {
        if ((y == 0 || y == game->map->rows - 1)
            && !is_row_all_walls(game->map->map2d[y]))
            return (ft_printf("Error: Top/bottom not all walls.\n"), 1);
        if (game->map->map2d[y][0] != '1'
            || game->map->map2d[y][game->map->columns - 1] != '1')
            return (ft_printf("Error: Sides not walls.\n"), 1);
        y++;
    }
    return (0);
}
