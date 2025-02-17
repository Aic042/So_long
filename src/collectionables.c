/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectionables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:36:23 by root              #+#    #+#             */
/*   Updated: 2025/02/17 10:45:05 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int collect_count(t_game *game)
{
	int total;
	int y;
	int x;

	total = 0;
	x = 0;
	y = 0;
	while (game->map->map[y][x])
	{
		if(game->map[i][0] == 'c')
		{
			total++;
			y++;
		}
		x++;
	}
	
}