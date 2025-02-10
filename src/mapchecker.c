/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:44:55 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/10 15:34:28 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//-------------------------------------------------------------------------
void ft_parse_line()
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
void ft_check_counts(int E, int P, int C)
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
// -----------------------------------------------------------------------------
//Check_map_validity

void ft_check_map_validity(char *line)
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

// -----------------------------------------------------------------------------

 int main()
 {
     ft_check_map_validity("maps/ma.ber");
     return (0);
 }

 //gcc -o test mapchecker.c get_next_line.c get_next_line_utils.c -LMLX42/build -lmlx42 -lglfw -ldl -lm -lpthread -IMLX42/include && ./test
