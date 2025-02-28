/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:28:11 by root              #+#    #+#             */
/*   Updated: 2025/02/28 17:09:57 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	   ft_validate_line_length(char	*str_map)
{
	int	    i;
	int	    count_first_line;
	int	    count_other_lines;

	i = 0;
	count_first_line = 0;
	count_other_lines = 0;
	while (str_map[i] != '\n')
	{
		count_first_line++;
		i++;
	}
	i++;
	while (str_map[i] != '\0')
	{
		if (str_map[i] == '\n')
		{
				if (count_other_lines != count_first_line)
						ft_printf("Rotten");
		}
		else
				count_other_lines++;
		i++;
	}
}

int	ft_map_empty(char **map)
{
    if(map == NULL)
        return 1;
    else
    	return 0;
}

int	ft_validate_walls(t_game *game)
{
    int	y;

    y = 0;
    // game->map->rows = ft_count_strings(game->map->map2d);
    // game->map->columns = ft_strlen(game->map->map2d[0]);

    if (!game || !game->map || !game->map->map2d)
    {
        ft_printf("Error: Invalid game or map data.\n");
        exit(1);
    }
    while (y < game->map->rows)
    {
        if ((y == 0 || y == game->map->rows - 1) && !is_row_surrounded_by_walls(game->map->map2d[y])){
            ft_printf("Error: El mapa no está rodeado de muros.\n");
            exit(1);
        }
        if (game->map->map2d[y][0] != '1' || game->map->map2d[y][game->map->columns - 1] != '1')
        {
            ft_printf("Error: El mapa no está rodeado de muros.\n");
            exit(1);
        }
        y++;
    }
	return 0;
}

int	validate_map(char **map, t_game *game)
{
	if (ft_map_empty(map) == 0)
		return (ft_printf("Msg is wrong"), FALSE);
	// if (rectangle_map(map) == FALSE)
	// 	return (ft_printf("Map Shape is odd"), FALSE);
	// if (wrong_map(map) == FALSE)
	// 	return (ft_printf("Map is not okay"), FALSE);
	if (ft_validate_walls(game) == FALSE)
		return (ft_printf(E_WALLS), FALSE);
	return (TRUE);
}
