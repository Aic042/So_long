/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:44:55 by aingunza          #+#    #+#             */
/*   Updated: 2024/12/06 17:06:53 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
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
    int fd = open("map2.ber", O_RDONLY);
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


// -----------------------------------------------------------------------------

 int main()
 {
     ft_check_map_validity("map.ber");
     return (0);
 }

 //gcc -o test mapchecker.c get_next_line.c get_next_line_utils.c -LMLX42/build -lmlx42 -lglfw -ldl -lm -lpthread -IMLX42/include && ./test
