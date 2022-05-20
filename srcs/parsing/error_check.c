/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:36:55 by cdine             #+#    #+#             */
/*   Updated: 2022/05/20 13:53:13 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_checkextension(char *file)
{
	int	i;

	if (ft_strlen(file) < 5)
		return (ERROR);
	i = ft_strlen(file) - 4;
	if (file[i] == '.' && file[i + 1] == 'c' && file[i + 2] == 'u'
		&& file[i + 3] == 'b' && file[i - 1] != '/')
		return (NOERR);
	else
		return (ERROR);
}

int	check_presence_all_instructions(t_prog *cub3d)
{
	if (cub3d->ceiling.b == -1 || cub3d->floor.b == -1 || cub3d->no_text.path == NULL
		|| cub3d->ea_text.path == NULL || cub3d->we_text.path == NULL || cub3d->so_text.path == NULL)
		printf("Error\n");
	if (cub3d->ceiling.b == -1)
		printf("Ceiling color instruction missing\n");
	if (cub3d->floor.b == -1)
		printf("Floor color instruction missing\n");
	if (cub3d->no_text.path == NULL)
		printf("North texture instruction missing\n");
	if (cub3d->ea_text.path == NULL)
		printf("East texture instruction missing\n");
	if (cub3d->we_text.path == NULL)
		printf("West texture instruction missing\n");
	if (cub3d->so_text.path == NULL)
		printf("South texture instruction missing\n");
	if (cub3d->ceiling.b == -1 || cub3d->floor.b == -1 || cub3d->no_text.path == NULL
		|| cub3d->ea_text.path == NULL || cub3d->we_text.path == NULL || cub3d->so_text.path == NULL)
		return (ERROR);
	return (NOERR);
}

int	check_error(char **file, t_prog *cub3d)
{
	int	i;
 
	i = -1;
	while (file[++i])
	{
		if (ft_strncmp(file[i], "NO ", 3) == 0 || ft_strncmp(file[i], "SO ", 3) == 0
			 || ft_strncmp(file[i], "WE ", 3) == 0 || ft_strncmp(file[i], "EA ", 3) == 0)
		{
			if (get_wall_texture(cub3d, file[i]) == ERROR)
				return (printf("Error\nWrong instructions format: wall texture, line %d\n", i + 1), ERROR);
		}
		else if (ft_strncmp(file[i], "F ", 2) == 0 || ft_strncmp(file[i], "C ", 2) == 0)
		{
			if (get_f_c_texture(cub3d, file[i]) == ERROR)
				return (printf("Error\nWrong instructions format: floor and ceiling color, line %d\n", i + 1), ERROR);
		}
		else if (file[i][0] == '1')
		{
			if (get_map(cub3d, &file[i], i + 1) == ERROR)
				return (ERROR);
			break ;
		}
		else if (file[i][0] != '\n') // checker poour ligne full d'espaces vide ?
			return (printf("Error\nWrong instructions format: instruction not recognized, line %d\n", i + 1), ERROR);
	}
	if (check_presence_all_instructions(cub3d) == ERROR)
		return (ERROR);
	return (NOERR);
}