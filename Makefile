NAME = SO_LONG

SRCS = ./FillMap.c \
	   ./Get_Next_Line/get_next_line.c \
	   ./Get_Next_Line/get_next_line_utils.c \
	   ./Helpers/Helper_1.c \
	   ./Helpers/Helper_2.c \
	   ./Map_Check.c \
	   ./movements.c \
	   ./so_long.c \
	   ./windowcontrol.c \
	   ./windowcreation.c \
	   ./FT_PRINTF/ft_printf.c \
       ./FT_PRINTF/Library/ft_printp_fd.c \
	   ./FT_PRINTF/Library/ft_putchar_fd.c \
	   ./FT_PRINTF/Library/ft_puthex_fd.c \
	   ./FT_PRINTF/Library/ft_putnbr_fd.c \
	   ./FT_PRINTF/Library/ft_putstr_fd.c \
	   ./FT_PRINTF/Library/ft_putu_fd.c

OBJS = $(SRCS:.c=.o)
CC = cc
FRAMEWORKS = -framework OpenGL -framework AppKit
LIBRARIES = -lmlx
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBRARIES) $(FRAMEWORKS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

