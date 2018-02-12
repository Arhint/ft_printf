cmake_minimum_required(VERSION 3.9)
project(ft_printf_new)

set(CMAKE_CXX_STANDARD 11)

add_executable(ft_printf_new
        includes/ft_printf.h
        includes/libft.h
        ft_atoll.c
        ft_blanks.c
        ft_create_flg.c
        ft_doflagxo.c
        ft_isdigit.c
        ft_itoa_base.c
        ft_print_c.c
        ft_print_di.c
        ft_print_flags.c
        ft_print_o.c
        ft_print_p.c
        ft_print_s.c
        ft_print_u.c
        ft_print_x.c
        ft_printf.c
        ft_putchar.c
        ft_putstr.c
        ft_strchr.c
        ft_strcpy.c
        ft_strdup.c
        ft_strlen.c
        ft_toupper.c
        main.c)
