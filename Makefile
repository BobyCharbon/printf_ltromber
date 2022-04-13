SRCS = ft_inter_gotaga.c ft_union.c

HEADERS += ft_printf.h

OBJS = ${SRCS:.c=.o}

CFLAGS += -Wall
FLAGS += -Werror
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