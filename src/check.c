/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:36:23 by lnicolos          #+#    #+#             */
/*   Updated: 2024/06/20 16:36:24 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	**init_visited(t_game *game)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(sizeof(int *) * game->heightmap);
	if (!visited)
		free_int_memory(&visited);
	i = 0;
	while (i < game->heightmap)
	{
		visited[i] = malloc(sizeof(int) * game->widthmap);
		if (!visited[i])
		{
			free(visited[i]);
			return (0);
		}
		j = 0;
		while (j < game->widthmap)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	verify_feasibility(t_game *game)
{
	int	**visited;

	visited = init_visited(game);
	explore_find_player(game);
	explore_map(game, game->player_x, game->player_y, visited);
	explore_complete(game, visited);
	if (!game->exit_found)
	{
		ft_printf("Erreur : Carte impossible\n");
		exit_point(game);
	}
	free_visited(visited, game->heightmap);
}
