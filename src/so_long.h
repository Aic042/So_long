/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:55:47 by root              #+#    #+#             */
/*   Updated: 2025/02/03 18:53:55 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define E_WALLS "Check_pathChecker"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "../libutils/libft.h"

#define Err_Music "Error: Failed to stop the music or VLC was not running."
#define Err_Mem "There's a memory error. Gotta go back to check those leaks ."
#define	Err_assets
#define Err_arg
#define Err_map "map failing, we did not play Mario Maker enough"
#define	Err_File "What have you done to the file "
#define Err_Ber
#define Err_path "There is no correct path. Gotta go back to map making 😥"
#define Wall '1'
#define Collec 'C'
#define Player 'P'
#define Exit 'E'


typedef struct game
{
	t_textures *textures;
	t_map
	t_window
	t_position
} t_game;





void	ft_error(char *str, int error);
void	ft_stop_music(void);
void	ft_music(const char *script_path);
void	ft_boot_textures(t_game *game);
void    ft_clean_old_textures(t_game *game);
void	ft_parse_line();
void	ft_check_counts(int E, int P, int C); ;
void ft_check_map_validity(char *line);
void	ft_validate_line_length(char *str_map);



#endif