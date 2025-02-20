/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectionables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:36:23 by root              #+#    #+#             */
/*   Updated: 2025/02/20 11:09:26 by aingunza         ###   ########.fr       */
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
    while (game->map->map2d[y])
    {
        x = 0;
        while (game->map->map2d[y][x])
        {
            if (game->map->map2d[y][x] == 'c')
            {
                total++;
            }
            x++;
        }
        y++;
    }
    return (total);
}
