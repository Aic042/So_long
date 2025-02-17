#include "so_long.h"

void	ft_boot_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	game->textures->wall = mlx_load_png("../assets/wall.png");
//	game->textures->water = mlx_load_png("../assets/water.png");
	game->textures->floor = mlx_load_png("../assets/floor.png");
	game->textures->player = mlx_load_png("../assets/Marvin.png");
	game->textures->exit = mlx_load_png("../assets/exit.png");
}

void	ft_clean_old_textures(t_game *game)
{	
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->floor);
	mlx_delete_texture(game->textures->player);
	mlx_delete_texture(game->textures->exit);
	
}

void render_tile(t_game *game, char tile, int x, int y)
{
    if (tile == '1')
        mlx_image_to_window(game->window->mlx, game->textures->wall, x * Tile_Size, y * Tile_Size);
    else if (tile == 'C')
        mlx_image_to_window(game->window->mlx, game->textures->collectible, x * Tile_Size, y * Tile_Size);
    else if (tile == 'E')
        mlx_image_to_window(game->window->mlx, game->textures->exit, x * Tile_Size, y * Tile_Size);
    else if (tile == 'P')
        mlx_image_to_window(game->window->mlx, game->textures->player, x * Tile_Size, y * Tile_Size);
    else
        mlx_image_to_window(game->window->mlx, game->textures->floor, x * Tile_Size, y * Tile_Size);
}
