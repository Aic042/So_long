/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:33:57 by root              #+#    #+#             */
/*   Updated: 2025/02/25 12:56:48 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_row_surrounded_by_walls(char *row)
{
    int len;

    if (!row)
        return (0);
    len = ft_strlen(row);
    // Check if the first and last characters of the row are '1'
    if (row[0] != '1' || row[len - 1] != '1')
        return (0);
    return (1);
}

int are_row_lengths_consistent(char **map, int rows)
{
    int i;
    size_t len;

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

int map_corners(char **map, int rows)
{
    int cols;

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

// void ft_validate_map(t_game *game)
// {
//     if (!are_row_lengths_consistent(game->map->map2d, game->map->rows))
//     {
//         ft_printf("Error: Las filas del mapa no son consistentes en longitud.\n");
//         exit(1);
//     }
//     if (!map_corners(game->map->map2d, game->map->rows))
//     {
//         ft_printf("Error: Las esquinas del mapa no están rodeadas de muros.\n");
//         exit(1);
//     }
//     ft_validate_walls(game);
// }
