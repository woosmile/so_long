NAME = so_long

MAKE = make
MFLAGS = -C

LIBFT_SRCS = \
libft/ft_strlen.c \
libft/ft_strdup.c \
libft/ft_split.c \
libft/ft_strncmp.c \
libft/ft_strjoin.c \
libft/ft_calloc.c \
libft/ft_itoa.c

FT_PRINTF_SRCS = \
ft_printf/ft_printf.c \
ft_printf/print_addr.c \
ft_printf/print_char.c \
ft_printf/print_hex.c \
ft_printf/print_nbr_u.c \
ft_printf/print_nbr.c \
ft_printf/print_str.c

MANDATORY_DIR = mandatory
MANDATORY_SRCS = \
mandatory/so_long.c \
mandatory/so_long_utils.c \
mandatory/check_map_main.c \
mandatory/input_map_data.c \
mandatory/check_map_escapable.c \
mandatory/queue_command.c \
mandatory/draw.c \
mandatory/move_position.c \
mandatory/detect.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

BONUS_DIR = bonus
BONUS_SRCS = \
bonus/so_long_bonus.c \
bonus/so_long_utils1_bonus.c \
bonus/so_long_utils2_bonus.c \
bonus/check_map_main_bonus.c \
bonus/input_map_data_bonus.c \
bonus/check_map_escapable_bonus.c \
bonus/queue_command_bonus.c \
bonus/draw_bonus.c \
bonus/move_position_bonus.c \
bonus/detect_bonus.c \
bonus/enemy_bonus.c 
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
	FINAL_DIR = $(BONUS_DIR)
else
	FINAL_DIR = $(MANDATORY_DIR)
endif

ifdef WITH_BONUS
	FINAL_SRCS = $(BONUS_SRCS)
else
	FINAL_SRCS = $(MANDATORY_SRCS)
endif

ifdef WITH_BONUS
	FINAL_OBJS = $(BONUS_OBJS)
else
	FINAL_OBJS = $(MANDATORY_OBJS)
endif

all : $(NAME)
bonus : 
	make WITH_BONUS=1 all

$(NAME) : $(FINAL_OBJS) $(FINAL_SRCS) $(FT_PRINTF_SRCS) $(LIBFT_SRCS)

$(FINAL_OBJS) : $(FINAL_SRCS)
	$(MAKE) $(MFLAGS) $(FINAL_DIR) all

clean :
	$(MAKE) $(MFLAGS) $(MANDATORY_DIR) clean
	$(MAKE) $(MFLAGS) $(BONUS_DIR) clean


fclean : clean
	$(MAKE) $(MFLAGS) $(MANDATORY_DIR) fclean
	$(MAKE) $(MFLAGS) $(BONUS_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re