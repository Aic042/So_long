/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:51:37 by root              #+#    #+#             */
/*   Updated: 2025/02/20 19:27:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_validate_file(char *map_path)
{
    char *file = ft_strrchr(map_path, '.');
    
    if (file == NULL || ft_strcmp(file, ".ber") != 0)
        ft_printf(Err_Ber);
}

char	*ft_read_map(char *map_path)
{
	char	*str_map;
	int		fd;
	char	c;
	int		count;

	count = 0;

	ft_validate_file(map_path);

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_printf(Err_File, 1);
	while (read(fd, &c, 1) == 1)
		count++;
	if (count == 0)
	{
		ft_printf(Err_File, 1);
		return (NULL);
	}
	str_map = (char *)malloc(sizeof(char) * (count + 1));
	if (!str_map)
	{
		ft_printf(Err_Mem, 1);
		return (NULL);
	}
	close(fd);
	fd = open(map_path, O_RDONLY);
	read(fd, str_map, count);
	str_map[count] = '\0';
	close(fd);
	return (str_map);
}

/*ft_read_map(char *map_path)
1º declaramos las variables :D
2º Tipica ejecucion de gnl (Con preveneción ante errores)
    Mientras haya algo por leer, que siga leyendo
    Le damos memoria y todo eso.
    luego cerramos y que nos devuelvas el str_map

*/
