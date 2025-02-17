/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:33:57 by root              #+#    #+#             */
/*   Updated: 2025/02/17 12:17:43 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_row_surrounded_by_walls(char *row)
{
    int i;
    i = 0;
    
    char **map;

    while (map[0][i])
    {
        /* code */
    }
    

    
}
void ft_validate_walls(t_game *game)
{
    int y;
    int x;
    
    y = 0;
    game->map->rows = ft_count_strings(game->map->map);
    game->map->columns = ft_strlen(game->map->map[0]);

    while (y < game->map->rows)
    {
        x = 0;
        while (x < game->map->columns)
        {
            // Verificar que las primeras y últimas filas sean completamente '1'
            if ((y == 0 || y == game->map->rows - 1) && game->map->map[y][x] != '1')
                ft_printf("Error: El mapa no está rodeado de muros.\n"), exit(1);

            // Verificar que la primera y última columna sean '1'
            if ((x == 0 || x == game->map->columns - 1) && game->map->map[y][x] != '1')
                ft_printf("Error: El mapa no está rodeado de muros.\n"), exit(1);
            
            x++;
        }
        y++;
    }
}

int are_row_lengths_consistent(char **map, int rows)
{
    ft_strlen(map[0]);
     
}

int map_corners(char **map, int rows)
{
    if (map[0][0] != '1' || map[0][rows - 1] != '1' || map[rows - 1][0] != '1' || map[rows - 1][rows - 1] != '1')
    {
        return (0);
    }
    return (1);
}
