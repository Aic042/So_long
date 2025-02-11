/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:44:55 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/11 10:57:54 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//-------------------------------------------------------------------------
void	ft_parse_line()
{    
    int i = 0;
    int E = 0;
    int P = 0;
    int C = 0;

    
    while(i != '\0')
        {
            if(i == 'E')
                E++;
            if (i == 'P')
                P++;
            if (i == 'C')
                C++;
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
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] == 'E')
                E++;
            if (line[i] == 'P')
                P++;
            if (line[i] == 'C')
                C++;
        }
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

