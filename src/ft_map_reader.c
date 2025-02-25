/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:51:37 by root              #+#    #+#             */
/*   Updated: 2025/02/25 14:58:05 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_validate_file(char *map_path)
{
    char *file = ft_strrchr(map_path, '.');
    
    if (file == NULL || ft_strcmp(file, ".ber") != 0)
        ft_printf(Err_Ber);
}

char **ft_read_map(char *map_path)
{
	int		fd;
	char	*temp_map;
	char	**map;
	int		n;

	n = 0;
	temp_map = ft_calloc(1000 + 1, sizeof(char));
	if (!temp_map)
		return (0);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (0);
	}
	n = read(fd, temp_map, 1000);
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
