/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 19:43:10 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/11 14:46:10 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <pthread.h>

typedef struct			s_pos
{
	int					x;
	int					y;
	int					etat;
}						t_pos;

typedef struct			s_all
{
	t_pos				point[8];
	pthread_mutex_t		baguette[7];
	pthread_mutex_t		ph[7];
	pthread_t			philo[7];
	char				*name[7];
	int					health[7];
	int					sleep[7];
	int					action[7];
	time_t				minus[7];
	int					reflec[7];
	int					current;
}						t_all;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	int					bpp;
	int					size_line;
	int					endian;
	char				*data;
	t_all				*all;
}						t_env;

#endif
