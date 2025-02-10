/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:57:58 by root              #+#    #+#             */
/*   Updated: 2025/02/10 16:28:47 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_2Dmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:53:55 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 16:19:06 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_strings(char **map_2d)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map_2d[i] != 0)
	{
		count++;
		i++;
	}
	return (count);
}

void	ft_validate_2dmap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->rows = ft_count_strings(game->map_2d);
	game->columns = ft_strlen(game->map_2d[0]);
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (x == 0 && game->map_2d[y][x] != '1')
				ft_printf(Err_map, 1);
			if (y == 0 && game->map_2d[y][x] != '1')
				ft_printf(Err_map, 1);
			if (x == game->columns - 1 && game->map_2d[y][x] != '1')
				ft_printf(Err_map, 1);
			if (y == game->rows - 1 && game->map_2d[y][x] != '1')
				ft_printf(Err_map, 1);
			x++;
		}
		y++;
	}
}

void

void	ft_path_checker_checker()
{
	if (!validate_path(&game))
	{
		ft_printf("Error: No hay camino válido en el mapa.\n");
		return (EXIT_FAILURE);
	}
}
void	end_game(t_game *game)
{
	if(game->player->instances[0] == game->map Exit)
	
}