SRC=main.c ft_atoi.c ft_print_env.c ft_putnbr_fd.c ft_putchar_fd.c ft_parse.c\
rt_philo.c ft_print_philo.c ft_init_meal.c ft_start_meal.c ft_philofork.c ft_philosay.c\
ft_memcpy.c ft_philotry.c ft_restaurant.c rt_waiter.c
OBJ=$(SRC:.c=.o)
NAME=philosophers
CFLAGS=-Wall -Werror -Wextra -g3 
CF=-lpthread
CC=cc
INCLUDES=philosopher.h

$(NAME) : $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

all : $(NAME)

re : fclean all

valt : $(NAME)
	valgrind ./$(NAME) 4 300 200 200
	valgrind ./$(NAME) 200 400 200 100 2

test : $(NAME)
	./$(NAME) 200 320 200 100
	./$(NAME) 200 400 200 100 2

.PHONY : clean flcean all re