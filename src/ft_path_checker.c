/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:57:58 by root              #+#    #+#             */
/*   Updated: 2025/03/06 12:04:40 by aingunza         ###   ########.fr       */
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
char **duplicate_map(t_game *game)
{
    char **copy;
    int y = 0;

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

// Helper function to free the duplicated map
void free_duplicate_map(char **map, int rows)
{
    int y = 0;
    while (y < rows)
        free(map[y++]);
    free(map);
}

// Modified ft_file_validator_map

// Modified ft_flood_doer to use a separate map
void ft_flood_doer(t_game *game, int y, int x, char **map)
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
    char **map_copy;
    int y, x;
    int collectibles = 0, exits = 0;

    // Find player position and duplicate map
    find_initial_position(game);
    map_copy = duplicate_map(game);
    if (!map_copy)
    {
        ft_printf("Error: Failed to duplicate map\n");
        return (1);
    }

    // Run flood-fill on the copy
    ft_flood_doer(game, game->player->y, game->player->x, map_copy);

    // Count reachable collectibles and exits in the copy
    y = 0;
    while (y < game->map->rows)
    {
        x = 0;
        while (x < game->map->columns)
        {
            if (map_copy[y][x] == 'X' && game->map->map2d[y][x] == 'C')
                collectibles++;
            if (map_copy[y][x] == 'X' && game->map->map2d[y][x] == 'E')
                exits++;
            x++;
        }
        y++;
    }

    // Free the copy
    free_duplicate_map(map_copy, game->map->rows);

    // Validate original map characters
    ft_validate_accessible_cells(game);

    // Check if all collectibles and the exit are reachable
    if (collectibles != collect_count(game) || exits != 1)
    {
        ft_printf("Error: Not all collectibles or exit are reachable\n");
        return (1);
    }

    return (0);
}