#include "so_long.h"

int collect_count(t_game *game)
{
    int total;
    int y;
    int x;

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

void coin_collecter(t_game *game)
{
    // Get the player's current position
    int player_x = game->player->x;
    int player_y = game->player->y;

    // Check if the player is on a collectible
    if (game->map->map2d[player_y][player_x] == 'C')
    {
        // Increment the collectible count
        game->player->count_collect++;

        // Replace the collectible with a floor tile
        game->map->map2d[player_y][player_x] = '0';

        // Update the display (if you have a collectible counter on the screen)
        ft_printf("Collected a coin! Total: %d\n", game->player->count_collect);
    }
}
