SRCS = ft_printf.c ft_print_c.c ft_print_d.c ft_print_x.c ft_print_xmaj.c ft_print_u.c ft_print_s.c ft_print_p.c ft_itoa_unsigned.c
SRCS_libft = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memcmp.c libft/ft_memmove.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strnstr.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_putchar_fd.c libft/ft_strtrim.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_itoa.c libft/ft_split.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c
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
	gcc -g $(SRCS) $(SRCS_libft)

clean:
	@echo Cleaning out those old .o
	
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo Cleaning out that old $(NAME)
	@rm -f $(NAME)

out:
	gcc -g $(CFLAGS) $(SRCS) $(SRCS_libft)
	@./a.out

cleanout:
	rm a.out

.PHONY:        all clean fclean re

