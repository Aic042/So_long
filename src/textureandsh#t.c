#include "so_long.h"

void	ft_boot_textures(t_game *game)
{
	game->textures = ft_calloc( sizeof());
	game->textures = mlx_load_png("../assets/wall.png");
	game->textures = mlx_load_png("../assets/water.png");
	game->textures = mlx_load_png("../assets/floor.png");
	game->textures = mlx_load_png("../assets/Marvin.png");
}
floor

void	   ft_clean_old_textures(t_game *game)
{
	mlx_delete_texture(game->texture);
	mlx_delete_texture(game->texture);
	mlx_delete_texture(game->texture);
	mlx_delete_texture(game->texture);
	mlx_delete_texture(textur		
}

void	render_tile(t_game *game, char tile, int x, int y)
{
    if (tile == '1')
        mlx_image_to_window(game->window->mlx, game->textures->wall_img, x * Tile_Size, y * Tile_Size);
    else if (tile == 'C')
        mlx_image_to_window(game->window->mlx, game->textures->caracter_img, x * Tile_Size, y * Tile_Size);
    else if (tile == 'E')
        mlx_image_to_window(game->window->mlx, game->textures->exit_img, x * Tile_Size, y * Tile_Size);
    else if (tile == 'P')
        mlx_image_to_window(game->window->mlx, game->textures->player_img, x * Tile_Size, y * Tile_Size);
    else
        mlx_image_to_window(game->window->mlx, game->textures->background_img, x * Tile_Size, y * Tile_Size);
}