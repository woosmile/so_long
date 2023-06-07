NAME = ../so_long

CC = cc
CFLAGS = -Werror -Wall -Wextra

MAKE = make
MFLAGS = -C

RM = rm
RMFLAGS = -rf

LIBFT_SRCS = \
../libft/ft_strlen.c \
../libft/ft_strdup.c \
../libft/ft_split.c \
../libft/ft_strncmp.c \
../libft/ft_strjoin.c \
../libft/ft_calloc.c

FT_PRINTF_DIR = ../ft_printf
FT_PRINTF_SRCS = \
../ft_printf/ft_printf.c \
../ft_printf/print_addr.c \
../ft_printf/print_char.c \
../ft_printf/print_hex.c \
../ft_printf/print_nbr_u.c \
../ft_printf/print_nbr.c \
../ft_printf/print_str.c
FT_PRINTF_LIB = libftprintf.a

MANDATORY_SRCS = \
so_long.c \
so_long_utils.c \
check_map_main.c \
input_map_data.c \
check_map_escapable.c \
queue_command.c \
draw.c \
move_position.c \
detect.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

MINILIBX_DIR = ../minilibx

all : $(NAME)

$(NAME) : $(MANDATORY_OBJS) $(LIBFT_SRCS) $(FT_PRINTF_SRCS)
	$(MAKE) $(MFLAGS) $(FT_PRINTF_DIR) all
	$(MAKE) $(MFLAGS) $(MINILIBX_DIR) all
	$(CC) $(CFLAGS) -o $@ $(MANDATORY_OBJS) \
	-L../ft_printf -lftprintf \
	-L../minilibx -lmlx \
	-framework OpenGL \
	-framework Appkit

$(MANDATORY_OBJS) : $(MANDATORY_SRCS) 
	$(CC) $(CFLAGS) -c $^

clean :
	$(MAKE) $(MFLAGS) $(FT_PRINTF_DIR) clean
	$(MAKE) $(MFLAGS) $(MINILIBX_DIR) clean
	$(RM) $(RMFLAGS) $(MANDATORY_OBJS)

fclean : clean
	$(MAKE) $(MFLAGS) $(FT_PRINTF_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re