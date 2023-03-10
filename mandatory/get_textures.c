/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:06:20 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/11 02:03:24 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img->data + (y * mlx->img->size_l + x * (mlx->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	east_add(t_mlx *mlx, t_ray *ray, int i, int x)
{
	char	*str;

	ray->offset_y = (i + (ray->wall_height / 2) - (WIN_H / 2))
		* ((double)mlx->mp->no->height / ray->wall_height);
	if (ray->offset_y < 0)
		ray->offset_y = 0;
	str = mlx->mp->ea->data + (ray->offset_y * mlx->mp->ea->size_l
			+ ray->offset_x * (mlx->mp->ea->bpp / 8));
	my_mlx_pixel_put(mlx, x, i, *(unsigned int *)str);
}

void	west_add(t_mlx *mlx, t_ray *ray, int i, int x)
{
	char	*str;

	ray->offset_y = (i + (ray->wall_height / 2) - (WIN_H / 2))
		* ((double)mlx->mp->no->height / ray->wall_height);
	if (ray->offset_y < 0)
		ray->offset_y = 0;
	str = mlx->mp->we->data + (ray->offset_y * mlx->mp->we->size_l
			+ ray->offset_x * (mlx->mp->we->bpp / 8));
	my_mlx_pixel_put(mlx, x, i, *(unsigned int *)str);
}

void	south_add(t_mlx *mlx, t_ray *ray, int i, int x)
{
	char	*str;

	ray->offset_y = (i + (ray->wall_height / 2) - (WIN_H / 2))
		* ((double)mlx->mp->no->height / ray->wall_height);
	if (ray->offset_y < 0)
		ray->offset_y = 0;
	str = mlx->mp->so->data + (ray->offset_y * mlx->mp->so->size_l
			+ ray->offset_x * (mlx->mp->so->bpp / 8));
	my_mlx_pixel_put(mlx, x, i, *(unsigned int *)str);
}

void	north_add(t_mlx *mlx, t_ray *ray, int i, int x)
{
	char	*str;

	ray->offset_y = (i + (ray->wall_height / 2) - (WIN_H / 2))
		* ((double)mlx->mp->no->height / ray->wall_height);
	if (ray->offset_y < 0)
		ray->offset_y = 0;
	str = mlx->mp->no->data + (ray->offset_y * mlx->mp->no->size_l
			+ ray->offset_x * (mlx->mp->no->bpp / 8));
	my_mlx_pixel_put(mlx, x, i, *(unsigned int *)str);
}
