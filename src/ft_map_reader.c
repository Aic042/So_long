/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:51:37 by root              #+#    #+#             */
/*   Updated: 2024/12/20 00:06:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_validate_file(const char *map_path)
{
    const char *file = ft_strrchr(map_path, '.');
    
    if (file == NULL || ft_strcmp(file, ".ber") != 0)
        ft_error_message(E_FORMAT, 1);
}


/*
    busca el arg que es un .ber
*/
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
		ft_error_message(E_FILE, 1);
	while (read(fd, &c, 1) == 1)
		count++;
	if (count == 0)
		ft_error_message(E_EMPTYFILE, 1);
	str_map = (char *)malloc(sizeof(char) * (count + 1));
		ft_error_message(E_MALLOC, 1);
	close(fd);
	fd = open(map_path, O_RDONLY);
	read(fd, str_map, count);
	str_map[count] = '\0';
	return (str_map);
}

/*ft_read_map(char *map_path)
1º declaramos las variables :D
2º Tipica ejecucion de gnl (Con preveneción ante errores)
    Mientras haya algo por leer, que siga leyendo
    Le damos memoria y todo eso.
    luego cerramos y que nos devuelvas el str_map

*/
