NAME = libftprintf.a

CC = cc
CFLAGS = -Werror -Wall -Wextra

AR = ar
ARFLAGS = rcs

MAKE = make
MFLAGS = -C

RM = rm
RMFLAGS = -rf

CP = cp

MANDATORY_SRCS = \
ft_printf.c \
print_addr.c \
print_char.c \
print_hex.c \
print_nbr_u.c \
print_nbr.c \
print_str.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

LIBFT_DIR = ../libft
LIBFT_SRCS = \
../libft/ft_strlen.c
LIBFT_LIB = libft.a

all : $(NAME)

$(NAME) : $(MANDATORY_OBJS) $(LIBFT_SRCS)
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) all
	$(CP) $(LIBFT_DIR)/$(LIBFT_LIB) ./$(NAME)
	$(AR) $(ARFLAGS) $@ $(MANDATORY_OBJS)

$(MANDATORY_OBJS) : $(MANDATORY_SRCS)
	$(CC) $(CFLAGS) -c $(MANDATORY_SRCS)

clean :
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(MANDATORY_OBJS)

fclean : clean
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re