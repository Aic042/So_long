/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:44:55 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/20 19:27:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//-------------------------------------------------------------------------
void	ft_parse_line(char *line, int *E, int *P, int *C)
{    
    int i = 0;

    while (line[i] != '\0')
    {
        if (line[i] == 'E')
            (*E)++;
        if (line[i] == 'P')
            (*P)++;
        if (line[i] == 'C')
            (*C)++;
        i++;
    }
}
// -----------------------------------------------------------------------------
//Check_Counts
void    ft_check_counts(int E, int P, int C)
{
        if (E != 1 || P != 1 || C < 1)
        {
            printf("map couldn't be loaded 😔\n");
            return;
        }
        else
        {
            printf("Map loaded successfully 🥳\n");
            return;
        }
}
int is_valid_char(char c)
{
	if (c == 'C' || c == 'E' || c == 'P' || c == '1' || c == '0')
		return (1);
	return (0);
}
// -----------------------------------------------------------------------------
//Check_map_validity

void	ft_check_map_validity(char *line)
 {
    int E = 0, P = 0, C = 0;
    int fd = open("maps/map.ber", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return;
    }
    while ((line = get_next_line(fd)))
    {
        ft_parse_line(line, &E, &P, &C);
        free(line);
    }
    close(fd);

    ft_check_counts(E, P, C);
 }

void	ft_validate_line_length(char *str_map)
{
	int	i;
	int	count_first_line;
	int	count_other_lines;

	i = 0;
	count_first_line = 0;
	count_other_lines = 0;
	while (str_map[i] != '\n')
	{
		count_first_line++;
		i++;
	}
	i++;
	while (str_map[i] != '\0')
	{
		if (str_map[i] == '\n')
		{
			if (count_other_lines != count_first_line)
				ft_printf("Rotten");
			count_other_lines = 0;
		}
		else
			count_other_lines++;
		i++;
	}
}

void    char_validator() 
{
    
}

