#include "so_long.h"

int init_game(t_game *game)
{
    game->player = malloc(sizeof(t_player));
    game->textures = malloc(sizeof(t_textures));
    game->window = malloc(sizeof(t_window));
    if (!game->player || !game->textures || !game->window)
        return (1);
    game->player->move_count = 0;
    game->player->count_collect = 0;
    game->window->mlx = mlx_init(game->map->columns * Tile_Size, game->map->rows * Tile_Size, "so_long", false);
    if (!(game->window->mlx))
        return (1);
    ft_boot_textures(game);
    images_to_textures(game);
    draw_map(game);
    mlx_key_hook(game->window->mlx, ft_hook, game);
    mlx_loop_hook(game->window->mlx, mlx_loop, game);
    mlx_loop(game->window->mlx);
    return 0;
}

int main(int argc, char **argv)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
        return (ft_printf(Err_Mem), 1);
    if (argc != 2)
        return (ft_printf(Err_arg), ft_end_game(game), 1);
    ft_validate_file(argv[1]);
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (ft_printf(Err_Mem), ft_end_game(game), 1);
    game->map->map2d = ft_read_map(argv[1]);
    if (!game->map->map2d)
        return (ft_end_game(game), 1);
    ft_validate_map(game);
    if (init_game(game) == FALSE)
        return (ft_end_game(game), 1);
    ft_end_game(game);
    return 0;
}