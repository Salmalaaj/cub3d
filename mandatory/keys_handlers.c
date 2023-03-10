/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:00:55 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/10 04:49:25 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	escp_handler(int keyCode, t_mlx *mlx)
{
	printf("ESC\n");
	exit(0);
}

int	key_press(int keyCode, t_mlx *mlx)
{
	if (keyCode == ESC)
		escp_handler(keyCode, mlx);
	if (keyCode == W_KEY)
		mlx->plyr->walk_direction = +1;
	else if (keyCode == S_KEY)
		mlx->plyr->walk_direction = -1;
	else if (keyCode == A_KEY)
		mlx->plyr->walk_rotation = +1;
	else if (keyCode == D_KEY)
		mlx->plyr->walk_rotation = -1;
	else if (keyCode == RIGHT_ARROW)
		mlx->plyr->turn_direction = +1;
	else if (keyCode == LEFT_ARROW)
		mlx->plyr->turn_direction = -1;
	else
		return (0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img->data = mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp,
			&mlx->img->size_l, &mlx->img->endian);
	update_window(mlx);
	return (0);
}

int	key_release(int keyCode, t_mlx *mlx)
{
	if (keyCode == W_KEY)
		mlx->plyr->walk_direction = 0;
	else if (keyCode == S_KEY)
		mlx->plyr->walk_direction = 0;
	else if (keyCode == A_KEY)
		mlx->plyr->walk_rotation = 0;
	else if (keyCode == D_KEY)
		mlx->plyr->walk_rotation = 0;
	else if (keyCode == RIGHT_ARROW)
		mlx->plyr->turn_direction = 0;
	else if (keyCode == LEFT_ARROW)
		mlx->plyr->turn_direction = 0;
	return (0);
}
