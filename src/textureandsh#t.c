#include "so_long.h"

void ft_boot_textures(t_game *game)
{
	game->textures = ft_calloc( sizeof());
	game->textures = mlx_load_png("../assets/wall.png");
	game->textures = mlx_load_png("../assets/water.png");
	game->textures = mlx_load_png("../assets/floor.png");
	game->textures = mlx_load_png("../assets/Marvin.png");
}
floor

void    ft_clean_old_textures(t_game *game)
{
    mlx_delete_image(game->mlx, game->player);
}