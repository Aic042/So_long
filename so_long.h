/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:55:47 by root              #+#    #+#             */
/*   Updated: 2024/12/16 19:44:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

typedef struct textures
{
    	mlx_image_t		*bush;
	mlx_image_t		*squirrel;
	mlx_image_t		*acorn;
	mlx_image_t		*tree;
	mlx_image_t		*floor;
} t_textures;


#endif