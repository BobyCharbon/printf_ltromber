SRCS = ft_printf.c ft_format_c.c ft_format_d.c ft_format_i.c ft_format_x.c ft_format_xmaj.c ft_format_u.c ft_format_s.c ft_format_p.c ft_itoa_unsigned.c ft_itoa.c ft_strlen.c

HEADERS += ft_printf.h

PATH_OBJS = objs/

OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

#CFLAGS += -Wall
#CFLAGS += -Werror
#CFLAGS += -Wextra

CC = clang

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(PATH_OBJS) $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo "OK"

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


$(PATH_OBJS):
	mkdir $@

re:	fclean
	$(MAKE)

clean:
	$(RM) -R $(PATH_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

out:
	$(CC) -g $(CFLAGS) $(SRCS) && ./a.out

cleanout:
	$(RM) a.out

.PHONY: all clean fclean re
#.SILENT:
