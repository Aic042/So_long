/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:57:58 by root              #+#    #+#             */
/*   Updated: 2025/03/17 14:29:06 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Helper function to duplicate the map
char	**duplicate_map(t_game *game)
{
	char	**copy;
	int		y;

	y = 0;
	copy = malloc(sizeof(char *) * (game->map->rows + 1));
	if (!copy)
		return (NULL);
	while (y < game->map->rows)
	{
		copy[y] = ft_strdup(game->map->map2d[y]);
		if (!copy[y])
		{
			while (--y >= 0)
				free(copy[y]);
			free(copy);
			return (NULL);
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

void	free_duplicate_map(char **map, int rows)
{
	int	y;

	y = 0;
	while (y < rows)
		free(map[y++]);
	free(map);
}

void	ft_flood_doer(t_game *game, int y, int x, char **map)
{
	if (x < 0 || y < 0 || x >= game->map->columns || y >= game->map->rows
		|| map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C')
		game->temp_collec++;
	map[y][x] = 'X';
	ft_flood_doer(game, y + 1, x, map);
	ft_flood_doer(game, y - 1, x, map);
	ft_flood_doer(game, y, x + 1, map);
	ft_flood_doer(game, y, x - 1, map);
}

int	element_counter(t_game *game, char **map_cpy, int *collec, int *exit)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->columns)
		{
			if (map_cpy[y][x] == 'X' && game->map->map2d[y][x] == 'C')
				(*collec)++;
			if (map_cpy[y][x] == 'X' && game->map->map2d[y][x] == 'E')
				(*exit)++;
			x++;
		}
		y++;
	}
	return (0);
}

int	has_no_empty_lines(t_game *game)
{
	int		y;
	char	*row;

	y = 0;
	while (y < game->map->rows)
	{
		row = game->map->map2d[y];
		if (!row || row[0] == '\n')
			return (0);
		y++;
	}
	return (1);
}

int	has_one_exit(t_game *game)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->columns)
		{
			if (game->map->map2d[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	ft_file_validator_map(t_game *game)
{
	char	**map_copy;
	int		collecs;
	int		exits;

	collecs = 0;
	exits = 0;
	if (!has_no_empty_lines(game))
        return (ft_printf("Error: Map contains empty lines\n"), 1);
	if (!has_one_exit(game))
		return (ft_printf("Error: Must have exactly one exit\n"), 1);
	if (find_initial_position(game) != 0)
		return (1);
	map_copy = duplicate_map(game);
	if (!map_copy)
		return (ft_printf("Error: Failed to duplicate map\n"), 1);
	game->temp_collec = 0;
	ft_flood_doer(game, game->player->y, game->player->x, map_copy);
	element_counter(game, map_copy, &collecs, &exits);
	free_duplicate_map(map_copy, game->map->rows);
	if (collecs != game->total_colec)
		return (ft_printf("Error: Not all collecs or exit reachable\n"), 1);
	return (0);
}
