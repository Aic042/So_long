#include "so_long.h"

void	hook(void	*param)
{
	t_game	*game;

	game = param;
	ft_put_image_in_map(game);
}

void	ft_initialize_variables(t_game *game)
{
	game->move_count = 0;
	game->state = STATE_NULL;
	game->exit_flag = FALSE;
}

int	main(int argc, char **argv, t_game *game)
{
	char	*str_map;

	if (argc != 2)
		ft_printf(Err_arg, 1);
	str_map = ft_read_map(argv[1]);
	ft_initialize_variables(&game);
	ft_validate_map(str_map, &game);
	game->map->map = ft_string_to_2d(str_map);
	free(str_map);
	ft_validate_2dmap(&game);
	ft_validate_path(&game);
	game->window->windows_width = game->map->columns * 64;
	game->window->windows_height = game->map->rows * 64;
	game->window->mlx = mlx_init(game->window->windows_width, game->window->windows_height, "MLX42", true);
	if (!game->window->mlx)
		exit(EXIT_FAILURE);
	ft_load_assets(&game);
	mlx_loop_hook(game->window->mlx, &hook, &game);
	mlx_key_hook(game->window->mlx, &ft_key_hook, &game);
	mlx_loop(game->window->mlx);
	ft_free_map(game->map);
	mlx_terminate(game->window->mlx);
	return (EXIT_SUCCESS);
}
