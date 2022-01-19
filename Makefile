SRCS = main.c ft_printf.c ft_itoa.c ft_print_c.c ft_print_d.c ft_print_x.c ft_print_xmaj.c ft_print_u.c ft_print_s.c

BONUS_SRCS = 

OBJS= ${SRCS:.c=.o}

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

#CFLAGS = -Wall -Werror -Wextra
NAME := libftprintf.a

all: $(NAME)

bonus:	$(BONUS_OBJS)
		ar -rcs $(NAME) $(BONUS_OBJS)

.c.o:
	@echo Compiling $<
	gcc -c $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@echo make $(NAME)
	ar -rcs $(NAME) $(OBJS)

re:	fclean $(NAME)

clean:
	@echo Cleaning out those old .o
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo Cleaning out that old $(NAME)
	@rm -f $(NAME)

out:
	gcc -g $(CFLAGS) $(SRCS)
	@./a.out

cleanout:
	rm a.out

.PHONY:        all clean fclean re

