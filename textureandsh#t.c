#include "so_long.h"

void ft_boot_textures(t_game *game)
{

}

void	ft_clean_old_assets(t_game *game)
{
    mlx_delete_image(game->mlx, game->player);
}