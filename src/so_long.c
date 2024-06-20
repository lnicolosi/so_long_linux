/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:36:53 by lnicolos          #+#    #+#             */
/*   Updated: 2024/06/20 17:26:55 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	while (line < game->heightmap)
	{
		if (game->map[line])
			free(game->map[line]);
		line++;
	}
	if (game->map)
		free(game->map);
	exit(0);
}

//check si plus de 25 lignes pour main c'est ok
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (ft_printf("Il faut choisir une map << .bor >>\n") && 0);
	else if (argc > 2)
		return (ft_printf("Erreur lors du choix de la map\n") && 0);
	ft_memset(&game, 0, sizeof(t_game));
	if (!reading_map(&game, argv))
		exit_point(&game);
	check_errors(&game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		exit_point(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.widthmap * PIX), \
					(game.heightmap * PIX), "so_long");
	if (!game.win_ptr)
		exit_point(&game);
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.win_ptr, controls_working, &game);
	mlx_hook(game.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_ptr);
}
