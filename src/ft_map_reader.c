/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:51:37 by root              #+#    #+#             */
/*   Updated: 2024/12/18 23:54:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <string.h>

void ft_validate_file(const char *map_path)
{
    const char *file = ft_strrchr(map_path, '.');
    
    if (file == NULL || ft_strcmp(file, ".ber") != 0)
        ft_error_message(E_FORMAT, 1);
}

