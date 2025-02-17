/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectionables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:36:23 by root              #+#    #+#             */
/*   Updated: 2025/02/17 20:08:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int collect_count(t_game *game)
{
    int total;
    int y;
    int x;

    total = 0;
    y = 0;
    while (game->map->map[y])
    {
        x = 0;
        while (game->map->map[y][x])
        {
            if (game->map->map[y][x] == 'c')
            {
                total++;
            }
            x++;
        }
        y++;
    }
    return (total);
}
