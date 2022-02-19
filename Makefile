SRCS = ft_printf.c ft_print_c.c ft_print_d.c ft_print_x.c ft_print_xmaj.c ft_print_u.c ft_print_s.c ft_print_p.c ft_itoa_unsigned.c ft_itoa.c ft_strlen.c

HEADERS += ft_printf.h

OBJS = ${SRCS:.c=.o}

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

CC = clang

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo "OK"

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


re:	fclean
	$(MAKE)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

out:
	$(CC) -g $(CFLAGS) $(SRCS) && ./a.out

cleanout:
	$(RM) a.out

.PHONY: all clean fclean re
#.SILENT: