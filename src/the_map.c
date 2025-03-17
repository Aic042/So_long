/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:52:27 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/17 15:05:45 by aingunza         ###   ########.fr       */
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
    int     fd;
    char    *line;
    char    **map;
    int     i = 0;

    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    map = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
    if (!map)
        return (close(fd), NULL);
    line = get_next_line(fd);
    while (line && i < BUFFER_SIZE)
    {
        map[i] = ft_strtrim(line, "\n"); // Trim newline
        free(line);
        line = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    free(line);
    close(fd);
    if (i == 0 || (i == BUFFER_SIZE && get_next_line(fd)))
        return (free_duplicate_map(map, i), NULL);
    return (map);
}
// {
// 	int		fd;
// 	char	*temp_map;
// 	char	**map;
// 	int		n;

// 	n = 0;
// 	temp_map = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!temp_map)
// 		return (0);
// 	fd = open(map_path, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		free(temp_map);
// 		return (0);
// 	}
// 	n = read(fd, temp_map, BUFFER_SIZE);
// 	if (n == -1 || n == 0)
// 	{
// 		free(temp_map);
// 		return (0);
// 	}
// 	map = ft_split(temp_map, '\n');
// 	free(temp_map);
// 	close(fd);
// 	return (map);
// }
