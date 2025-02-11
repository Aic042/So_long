/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:33:57 by root              #+#    #+#             */
/*   Updated: 2025/02/11 10:55:49 by aingunza         ###   ########.fr       */
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
int are_columns_surrounded_by_walls(char **map, int columns)
{
    
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
