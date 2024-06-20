/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:36:29 by lnicolos          #+#    #+#             */
/*   Updated: 2024/06/20 17:15:09 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	process_move(t_game *game, int newX, int newY)
{
	char	cell;

	cell = game->map[newY][newX];
	if (cell == 'E' && game->collectables != 0)
		return (0);
	if (cell == 'E' && game->collectables == 0)
	{
		ft_printf("Bravo tu as gagné !\n");
		exit_point(game);
	}
	if (cell == '0' || cell == 'C')
	{
		if (cell == 'C')
			game->collectables--;
		game->map[newY][newX] = 'P';
		game->map[game->y_axis][game->x_axis] = '0';
		game->x_axis = newX;
		game->y_axis = newY;
		game->counter++;
	}
	return (1);
}

static int	move_player(t_game *game, int command)
{
	int	newx;
	int	newy;

	newx = game->x_axis;
	newy = game->y_axis;
	if (command == 119 || command == 65362)
		newy--;
	else if (command == 115 || command == 65364)
		newy++;
	else if (command == 97 || command == 65361)
		newx--;
	else if (command == 100 || command == 65363)
		newx++;
	if (newx < 0 || newy < 0 || newx >= game->widthmap \
		|| newy >= game->heightmap || game->map[newy][newx] == '1')
		return (0);
	return (process_move(game, newx, newy));
}

int	controls_working(int command, t_game *game)
{
	int	works;

	works = 0;
	if (command == 65307)
		exit_point(game);
	else
		works = move_player(game, command);
	if (works)
	{
		adding_in_graphics(game);
		ft_printf("Mouvement : %d\n", game->counter);
		ft_printf("Fleurs restantes : %d\n", game->collectables);
	}
	return (1);
}
