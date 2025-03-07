/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:44:55 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/07 12:31:17 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//-------------------------------------------------------------------------
void	ft_parse_line(char	*line, int	*E, int	*P, int	*C)
{
	int	i;

	i = 0;
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
// -----------------------------------------------------------------------------
//Check_map_validity

void	ft_check_map_validity(char	*line)
{
	int	E;
	int	P;
	int	C;
	int	fd;

	E = 0;
	P = 0;
	C = 0;
	fd = open("maps/map.ber", O_RDONLY);
	line = get_next_line(fd);

	if (fd == -1)
	{
		perror("Error opening file");
		return;
	}
	while ((line))
	{
		ft_parse_line(line, &E, &P, &C);
		free(line);
	}
	close(fd);
	ft_check_counts(E, P, C);
}
