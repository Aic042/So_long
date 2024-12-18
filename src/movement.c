/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:45 by root              #+#    #+#             */
/*   Updated: 2024/12/17 17:02:42 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 1000
#define HEIGHT 1000

static mlx_image_t* player;

// typedef struct player_texture
// {
// 	uint32_t	width;
// 	uint32_t	height;
// 	uint8_t		bytes_per_pixel;
// 	uint8_t*	pixels;
// }	player_texture_t;


void error()
{
    // Handle error
    exit(EXIT_FAILURE);
}

void ft_hook(mlx_key_data_t keydata, void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP)|| (mlx_is_key_down(mlx,MLX_KEY_W)))
		player->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx,MLX_KEY_S)))
		player->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx,MLX_KEY_A)))
		player->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || (mlx_is_key_down(mlx,MLX_KEY_D)))
	{
		player->instances[0].x += 5;
	}
}
int main()
{
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    if (!mlx)
        error();

    // Cargar textura desde archivo XPM
	mlx_texture_t* player_texture = mlx_load_png("assets/Marvin.png");
	if (!player_texture)
        error();

    // Convertir textura en una imagen para dibujar en la ventana
    player = mlx_texture_to_image(mlx, player_texture);
    if (!player)
        error();

    // Dibujar la imagen en la ventana
    if (mlx_image_to_window(mlx, player, 0, 0) < 0)
        error();

    // Registrar el hook de teclado para controlar el movimiento
    mlx_key_hook(mlx, ft_hook, mlx);

    // Bucle principal
    mlx_loop(mlx);
    mlx_delete_image(mlx, player);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
