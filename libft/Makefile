NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c		ft_isascii.c	ft_isprint.c \
		ft_strlen.c		ft_memset.c		ft_bzero.c			ft_memcpy.c		ft_memmove.c \
		ft_strlcpy.c	ft_strlcat.c	ft_toupper.c		ft_tolower.c	ft_strchr.c \
		ft_strrchr.c	ft_strncmp.c	ft_memchr.c			ft_memcmp.c		ft_strnstr.c \
		ft_atoi.c 		ft_calloc.c 	ft_strdup.c			ft_substr.c		ft_strjoin.c \
		ft_strtrim.c	ft_split.c		ft_itoa.c			ft_strmapi.c	ft_striteri.c \
		ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c		ft_putnbr_fd.c 	ft_printf.c \
		ft_printchar.c	ft_printstr.c	ft_printaddress.c	ft_printnbr.c	ft_printhexa.c \
		ft_print_unsigned_nbr.c			get_next_line.c

BONUS =	ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c \
		ft_lstadd_back.c	ft_lstdelone.c		ft_lstclear.c	ft_lstiter.c \
		ft_lstmap.c

OBJ_SRC = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_SRC)
	ar rcs $@ $(OBJ_SRC)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_SRC) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_SRC) $(OBJ_BONUS)

clean:
	rm -rf $(OBJ_SRC) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
