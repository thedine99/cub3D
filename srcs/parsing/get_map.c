/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:59:53 by cdine             #+#    #+#             */
/*   Updated: 2022/05/16 19:28:46 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	map_error_msg(int type)
{
	printf("Error\nWrong instructions format: ");
	if (type == 0)
		printf("Map not closed");
	else if (type == 1)
		printf("More than one starting point for player\n");
	else if (type == 2)
		printf("Element not recognized in map");
}

int	check_extremes(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\0')
			return (ERROR);
		i++;
	}
	return (NOERR);
}

int	check_elements_map(char **map, int line)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'N' || map[i][j] == 'S')
				count++;
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ')
				return (map_error_msg(2), printf(" line %d\n", line + i), ERROR);
			j++;
		}
		i++;
	}
	if (count != 1)
		return (map_error_msg(1), ERROR);
	return (NOERR);
}

int	check_middle(int j, char **map, int line)
{
	int	i;

	if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
		return (map_error_msg(0), printf(" line %d\n", line + j), ERROR);
	i = 0;
	while (map[j][i])
	{
		if (map[j][i] == '0' && (map[j][i - 1] == ' ' || map[j][i - 1] == '\0' 
			|| map[j][i + 1] == ' ' || map[j][i + 1] == '\0' 
			|| map[j - 1][i] == ' ' || map[j - 1][i] == '\0'
			|| map[j + 1][i] == ' ' || map[j + 1][i] == '\0'))
			return (map_error_msg(0), printf(" around line %d\n", line + j), ERROR);
		i++;
	}
	return (NOERR);
}

void	replace_backslash_n(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
			{
				map[i][j] = '\0';
				break ;
			}
			j++;
		}
		i++;
	}
}

void	replace_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int		get_map(t_prog *cub3d, char **map, int line)
{
	int	i;

	replace_backslash_n(map);
	replace_spaces(map);
	if (check_elements_map(map, line) == ERROR)
		return (ERROR);
	if (check_extremes(map[0]) == ERROR)
		return (map_error_msg(0), printf(" line %d\n", line), ERROR);
	i = 1;
	while (map[i + 1])
	{
		if (check_middle(i, map, line) == ERROR)
			return (ERROR);
		i++;
	}
	if (check_extremes(map[i]) == ERROR)
		return (map_error_msg(0), printf(" line %d\n", line + i), ERROR);
	cub3d->map = map;
	return (NOERR);
}