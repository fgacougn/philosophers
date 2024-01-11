/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:03:49 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 14:18:51 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <semaphore.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERR_MALLOC -1
# define SUCCESS -2
# define ERR_SEMAPHORE -3
# define DEATH -4
# define FAIL -5
# define ERR_BAD_READ -6

struct	s_env;

typedef struct s_philo
{
	int				number;
	int				die;
	int				eat;
	int				sleep;
	int				meals;
	int				smeals;
	int				hasmeals;
	int				pop;
	int				*parcae;
	int				*snip;
	int				*last_call;
	struct timeval	*start_time;
	struct timeval	current_time;
	struct timeval	last_meal;
	sem_t			*micro;
	struct s_env	*env;
	sem_t			*forks;
	sem_t			*ankou;
	sem_t			*start;
	sem_t			*meal;
	sem_t			*closing;
	sem_t			*end;
	int				(*try)(struct s_philo *, void (*f)(struct s_philo *, char *,
				int), char *, int);
}					t_philo;

typedef struct s_env
{
	sem_t			mutex;
	sem_t			start;
	sem_t			end;
	sem_t			ankou;
	sem_t			forks;
	sem_t			closing;
	sem_t			closed;
	sem_t			cptmeals;
	sem_t			ends;
	int				cptforks;
	int				ccptmeals;
	int				pop;
	int				cptends;
	int				die;
	int				eat;
	int				sleep;
	int				meals;
	struct timeval	start_time;
	struct timeval	current_time;
	t_philo			*party;
	pthread_t		*philos;
	pthread_t		waiter;
	int				parcae;
	int				snip;
	int				lastcall;
	int				(*try)(t_philo *, void (*f)(t_philo *, char *, int), char *,
			int);
}					t_env;

int					ft_atoi(const char *nptr);
size_t				ft_strlen(const char *s);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*rt_philo(void *param);
void				*rt_waiter(void *param);

void				ft_print_env(t_env *env);
int					ft_parse(int argc, char **argv, t_env *env);
int					ft_init_meal(t_env *env);
void				ft_start_meal(t_env *env);

int					ft_philofork(t_philo *philo, int wt);
//,						int (*try)(struct s_philo *, void (*f)(struct s_philo *,
//								char *, int), char *, int));
void				ft_print_philo(t_philo *philo);
void				ft_philosay(t_philo *philo, char *str, int opt);
int					ft_philotry(t_philo *philo, void (*f)(t_philo *, char *,
							int), char *str, int time);
int					ft_restaurant(t_philo *philo, void (*f)(t_philo *, char *,
							int), char *str, int time);

#endif