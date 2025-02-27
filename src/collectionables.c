#include "so_long.h"

int total_coin(t_game *game)
{}

int	collect_count(t_game	*game)
{
    int	total;
    int	y;
    int	x;

    total = 0;
    y = 0;
    while (game->map->map2d[y])
    {
        x = 0;
        while (game->map->map2d[y][x])
        {
            if (game->map->map2d[y][x] == 'C')
            {
                total++;
            }
            x++;
        }
        y++;
    }
    return (total);
}

void	coin_collecter(t_game *game)
{
    if (game->map->map2d[game->player->y][game->player->x] == 'C')
    {
        // Increment the collectible count
        game->player->count_collect++;

        // Replace the collectible with a floor tile
        game->map->map2d[game->player->y][game->player->x] = '0';

        // Update the display (if you have a collectible counter on the screen)
        ft_printf("Collected a coin! Total: %d\n", game->player->count_collect);

        // Check if all collectibles are collected
        if (game->player->count_collect == collect_count(game))
        {
            game->textures->exit->enabled = false;
        }
    }

    if (game->map->map2d[game->player->y][game->player->x] == 'E')
    {
        if (game->player->count_collect == collect_count(game))
        {
            exit(0);
        }
    }
}
