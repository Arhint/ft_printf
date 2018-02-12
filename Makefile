NAME = libftprintf.a

FLG =	-Iincludes -c


SRC =	ft_atoll.c \
		ft_blanks.c \
		ft_create_flg.c \
		ft_doflagxo.c \
		ft_isdigit.c \
		ft_itoa_base.c \
		ft_print_c.c \
		ft_print_di.c \
		ft_print_flags.c \
		ft_print_o.c \
		ft_print_p.c \
		ft_print_s.c \
		ft_print_u.c \
		ft_print_x.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strchr.c \
		ft_strcpy.c \
        ft_strdup.c \
		ft_strlen.c \
		ft_toupper.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLG) -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all