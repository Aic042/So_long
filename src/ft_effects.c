/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:34:05 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/10 15:34:28 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void effect_initializer(t_game *game)
{
	game->effects->lava_deadly = 1;
	game->effects->water_deadly = 0;
	game->effects->is_switched = 0;
	game->effects->times_switched = 0;
}

void transform(t_game *game)
{
	if(game->effects->is_switched == 1)
	{
		game->effects->lava_deadly = 1;
		game->effects->water_deadly = 0;
		game->effects->is_switched = 0;	
	}
	else
	{
		game->effects->lava_deadly = 0;
		game->effects->water_deadly = 1;
		game->effects->is_switched = 1;	
	}	
	game->effects->times_switched++;
	ft_printf("Times switched: %d\n", game->effects->times_switched);
}
