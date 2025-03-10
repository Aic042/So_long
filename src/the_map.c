/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:52:27 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/10 15:57:22 by aingunza         ###   ########.fr       */
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

void	ft_validate_file(char	*map_path)
{
	char	*file;

	file = ft_strrchr(map_path, '.');
	if (file == NULL || ft_strcmp(file, ".ber") != 0)
	{
		ft_printf(ERR_BER);
		exit(1);
	}
}

char	**ft_read_map(char	*map_path)
{
	int		fd;
	char	*temp_map;
	char	**map;
	int		n;

	n = 0;
	temp_map = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_map)
		return (0);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (0);
	}
	n = read(fd, temp_map, BUFFER_SIZE);
	if (n == -1 || n == 0)
	{
		free(temp_map);
		return (0);
	}
	map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (map);
}
