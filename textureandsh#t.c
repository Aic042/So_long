#include <MLX42/MLX42.h>

void	ft_clean_old_assets(t_game *game)
{
    mlx_delete_image(game->mlx, game->player);
}