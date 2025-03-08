/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:57:58 by root              #+#    #+#             */
/*   Updated: 2025/03/08 19:09:44 by root             ###   ########.fr       */
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

// Helper function to duplicate the map
char	**duplicate_map(t_game *game)
{
	char	**copy;
	int		y;

	y = 0;
	copy = malloc(sizeof(char *) * (game->map->rows + 1));
	if (!copy)
		return (NULL);
	while (y < game->map->rows)
	{
		copy[y] = ft_strdup(game->map->map2d[y]);
		if (!copy[y])
		{
			while (--y >= 0)
				free(copy[y]);
			free(copy);
			return (NULL);
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

void	free_duplicate_map(char **map, int rows)
{
	int	y;

	y = 0;
	while (y < rows)
		free(map[y++]);
	free(map);
}

void	ft_flood_doer(t_game *game, int y, int x, char **map)
{
	if (x < 0 || y < 0 || x >= game->map->columns || y >= game->map->rows
		|| map[y][x] == '1' || map[y][x] == 'X')
		return;
	map[y][x] = 'X';
	ft_flood_doer(game, y + 1, x, map);
	ft_flood_doer(game, y - 1, x, map);
	ft_flood_doer(game, y, x + 1, map);
	ft_flood_doer(game, y, x - 1, map);
}

int ft_file_validator_map(t_game *game)
{
    char    **map_copy;
    int     y;
    int     x;
    int     collecs;
    int     exits;

    collecs = 0;
    exits = 0;
    if (find_initial_position(game) != 0)
        return (1);
    map_copy = duplicate_map(game);
    if (!map_copy)
        return (ft_printf("Error: Failed to duplicate map\n"), 1);
    ft_flood_doer(game, game->player->y, game->player->x, map_copy);
    y = 0;
    while (y < game->map->rows)
    {
        x = 0;
        while (x < game->map->columns)
        {
            if (map_copy[y][x] == 'X' && game->map->map2d[y][x] == 'C')
                collecs++;
            if (map_copy[y][x] == 'X' && game->map->map2d[y][x] == 'E')
                exits++;
            x++;
        }
        y++;
    }
    free_duplicate_map(map_copy, game->map->rows);
    if (collecs != game->total_collectibles || exits != 1)
        return (ft_printf("Error: Not all collecs or exit reachable\n"), 1);
    return (0);
}
