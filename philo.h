/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 19:42:12 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/11 12:09:30 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <libft.h>
# include <time.h>
# include <mlx.h>
# include <X11/xlib.h>
# include <X11/cursorfont.h>
# include "lists.h"

# define MAX_LIFE 50
# define EAT_T 3
# define REST_T 2
# define THINK_T 2
# define TIMEOUT 60

# define SECOND 1000000
# define HEIGHT 1000
# define WIDTH 1500

# define WHITE 0xffffff
# define RED 0xff0000
# define GREEN 0x00cc00
# define YELLOW 0xcccc00
# define BLUE 0x0000cc
# define FUSHIA 0xcc00cc
# define CYAN 0xccffff
# define BROWN 0x999999

# define EXIT 65307

int		check_death(int *health);
void	init(t_all *all);
void	*eat(void *kalb);
void	*rest(void *kalb);
void	*think(void *kalb);
t_env	*init_mutex(t_all *all);
void	the_threads(t_all *all);

int		key_hook(int keycode, t_env *e);
void	ft_put_pixel_to_image(t_env *e, int x, int y, int color);
void	draw(t_env *e);
void	draw_stat(t_all all, t_env *e, int x);
void	draw_percent(t_all all, t_env *e);

#endif
