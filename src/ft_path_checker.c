/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:57:58 by root              #+#    #+#             */
/*   Updated: 2025/02/26 12:28:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     ft_count_strings(char **map)
{
        int     count;
        int     i;

        count = 0;
        i = 0;
        while (map[i] != 0)
        {
                count++;
                i++;
        }
        return (count);
}

void    ft_validate_2dmap(t_game *game)
{
        int     x;
        int     y;

        y = 0;
        game->map->rows = ft_count_strings(game->map->map2d);
        game->map->columns = ft_strlen(game->map->map2d[0]);

        while (y < game->map->rows)
        {
                x = 0;
                while (x < game->map->columns)
                {
                        if (x == 0 && game->map->map2d[y][x] != '1')
                                ft_printf(Err_map, 1);
                        if (y == 0 && game->map->map2d[y][x] != '1')
                                ft_printf(Err_map, 1);
                        if (x == game->map->columns - 1 && game->map->map2d[y][x] != '1')
                                ft_printf(Err_map, 1);
                        if (y == game->map->rows - 1 && game->map->map2d[y][x] != '1')
                                ft_printf(Err_map, 1);
                        x++;
                }
                y++;
        }
}

void ft_flood_doer(t_game *game, int y, int x)
{
    if (x < 0 || y < 0 || x >= game->map->columns || y >= game->map->rows
        || game->map->map2d[y][x] == '1' || game->map->map2d[y][x] == 'X')
    {
        return;
    }
    game->map->map2d[y][x] = 'X';
    ft_flood_doer(game, y + 1, x);
    ft_flood_doer(game, y - 1, x);
    ft_flood_doer(game, y, x + 1);
    ft_flood_doer(game, y, x - 1);
}
