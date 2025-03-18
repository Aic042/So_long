/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:52:27 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/18 18:09:06 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_game *game, char	**map)
{
	int	i;

	i = 0;
	game->map->columns = ft_strlen(map[0]);
	while (map[i])
		i++;
	game->map->rows = i;
	game->map_width = game->map->columns * T;
	game->map_height = game->map->rows * T;
}

int	ft_validate_file(char	*map_path)
{
	char	*file;

	file = ft_strrchr(map_path, '.');
	if (file == NULL || ft_strcmp(file, ".ber") != 0)
	{
		ft_printf(ERR_BER);
		return (0);
	}
	return (1);
}

char	**ft_read_map(char	*map_path)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!map)
		return (close(fd), NULL);
	i = 0;
	line = get_next_line(fd);
	while (line && i < BUFFER_SIZE)
	{
		map[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	if (i == 0 || (i == BUFFER_SIZE && get_next_line(fd)))
		return (free(line), free_duplicate_map(map, i), NULL);
	return (free(line), map);
}

// int is_exit_reachable(t_game *game, char **map_copy)
// {
//     int y = 0, x;
//     while (y < game->map->rows)
//     {
//         x = 0;
//         while (x < game->map->columns)
//         {
//             if (game->map->map2d[y][x] == 'E')
//             {
//                 if ((y > 0 && map_copy[y-1][x] == 'X') ||
//                     (y < game->map->rows-1 && map_copy[y+1][x] == 'X') ||
//                     (x > 0 && map_copy[y][x-1] == 'X') ||
//                     (x < game->map->columns-1 && map_copy[y][x+1] == 'X'))
//                     return (1);
//                 return (0);
//             }
//             x++;
//         }
//         y++;
//     }
//     return (0);
// }
