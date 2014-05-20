/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 05:24:23 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/11 09:27:59 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	draw_up(t_env *e)
{
	int		x;
	int		y;

	y = 170;
	while (y < 301)
	{
		x = 300;
		while (x < 1151)
		{
			if ((x >= 300 && x <= 570) || (x >= 590 && x <= 860) || x >= 880)
				ft_put_pixel_to_image(e, x, y, BROWN);
			x++;
		}
		y++;
	}
}

void	draw_middle(t_env *e)
{
	int		x;
	int		y;

	x = 300;
	while (x < 1151)
	{
		y = 330;
		while (y < 601)
		{
			if ((x >= 300 && x <= 430) || x >= 1020)
				ft_put_pixel_to_image(e, x, y, BROWN);
			y++;
		}
		x++;
	}
}

void	draw_down(t_env *e)
{
	int		x;
	int		y;

	y = 630;
	while (y < 761)
	{
		x = 450;
		while (x < 1011)
		{
			if (x <= 720 || x >= 740)
				ft_put_pixel_to_image(e, x, y, BROWN);
			x++;
		}
		y++;
	}
}

void	draw_names(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 420, 220, 0, "LINCOLN");
	mlx_string_put(e->mlx, e->win, 710, 220, 0, "EZIO");
	mlx_string_put(e->mlx, e->win, 1000, 220, 0, "PHILO");
	mlx_string_put(e->mlx, e->win, 350, 430, 0, "DIEU");
	mlx_string_put(e->mlx, e->win, 1070, 430, 0, "PIKACHU");
	mlx_string_put(e->mlx, e->win, 570, 680, 0, "VOLTAIRE");
	mlx_string_put(e->mlx, e->win, 860, 680, 0, "KAMINI");
}

void	draw(t_env *e)
{
	int		x;
	int		y;

	y = 150;
	while (y < 801)
	{
		x = 250;
		while (x < 1201)
		{
			ft_put_pixel_to_image(e, x, y, CYAN);
			x++;
		}
		y++;
	}
	draw_up(e);
	draw_middle(e);
	draw_down(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	draw_names(e);
}
