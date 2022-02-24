SRCS = ft_printf.c ft_format_c.c ft_format_d.c ft_format_i.c ft_format_x.c ft_format_xmaj.c ft_format_u.c ft_format_s.c ft_format_p.c ft_itoa_unsigned.c ft_itoa.c ft_strlen.c

HEADERS += ft_printf.h

OBJS = ${SRCS:.c=.o}

#CFLAGS += -Wall
#CFLAGS += -Werror
#CFLAGS += -Wextra

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