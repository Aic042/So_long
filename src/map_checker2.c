/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:43:09 by root              #+#    #+#             */
/*   Updated: 2025/02/27 12:54:43 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Check_Counts
void	ft_check_counts(int	E, int	P, int	C)
{
	if (E != 1 || P != 1 || C < 1)
	{
		printf("map couldn't be loaded 😔\n");
		return;
	}
	else
	{
		printf("Map loaded successfully 🥳\n");
		return;
	}
}

void	find_initial_position(t_game *game)
{
    int	y;
    int	x;
    
    y = 0;
    
    while (game->map->map2d[y])
    {
        x = 0;
        while (game->map->map2d[y][x])
        {
            if (game->map->map2d[y][x] == 'P')
            {
                game->player->x = x;
                game->player->y = y;
                return;
            }
            x++;
        }
        y++;
    }
}

void	ft_validate_accessible_cells(t_game *game)
{
    int	y;
    int	x;

    y = 0;
    while (game->map->map2d[y])
    {
        x = 0;
        while (game->map->map2d[y][x])
        {
            if (game->map->map2d[y][x] != '0' && game->map->map2d[y][x] != 'C' && game->map->map2d[y][x] != 'E')
            {
                ft_printf("Error: No cells.\n");
                exit(1);
            }
            x++;
        }
        y++;
    }
}

int	ft_file_validator_map(t_game *game)
{
    if (!game->map)
        return (ft_printf("Error: game->map is NULL before validator\n"), ft_end_game(game), 1);
    find_initial_position(game);
    ft_flood_doer(game, game->player->y, game->player->x);
    ft_validate_accessible_cells(game);
    return 0;
}
