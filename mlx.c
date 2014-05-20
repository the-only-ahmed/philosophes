/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 04:30:12 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/11 14:51:21 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		key_hook(int keycode, t_env *e)
{
	int		i;

	i = 0;
	if (keycode == EXIT)
	{
		while (i < 7)
		{
			pthread_mutex_destroy(&(e->all->baguette[i]));
			pthread_mutex_destroy(&(e->all->ph[i]));
			pthread_detach(e->all->philo[i]);
			i++;
		}
		exit(0);
	}
	return (0);
}

void	ft_put_pixel_to_image(t_env *e, int x, int y, int color)
{
	int		in;

	in = (x * (e->bpp >> 3)) + (y * e->size_line);
	e->data[in] = color & 0xff;
	e->data[in + 1] = (color & 0xff00) >> 8;
	e->data[in + 2] = (color & 0xff0000) >> 16;
}
