/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:52:27 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/26 22:33:39 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to free map
void free_map(t_game *game) {
    if (game->map) {
        if (game->map->map2d) {
            int i = 0;
            while (game->map->map2d[i]) {
                free(game->map->map2d[i]);
                i++;
            }
            free(game->map->map2d);
        }
        free(game->map);
    }
}
void size_map(t_game *game, char **map)
{
    int i;

    i = 0;
    game->map->rows = ft_strlen(map[0]) * 32;
    while (map[i])
        i++;
    game->map->columns = i * 32;
}
void ft_validate_file(char *map_path)
{
    char *file = ft_strrchr(map_path, '.');

    if (file == NULL || ft_strcmp(file, ".ber") != 0){
        ft_printf(Err_Ber);
        exit(1);
    }   
}

char **ft_read_map(char *map_path)
{
        int             fd;
        char    *temp_map;
        char    **map;
        int             n;

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