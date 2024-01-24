# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 15:31:39 by muhakose          #+#    #+#              #
#    Updated: 2024/01/13 14:14:08 by muhakose         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

COLOUR_GREEN = \033[0;32m
COLOUR_RED = \033[0;31m
COLOUR_BLUE = \033[0;34m
COLOUR_END = \033[0m

NAME		= so_long
RM          = rm -f

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

LIBMLX		= ./MLX42
MLX42_URL	= https://github.com/codam-coding-college/MLX42.git
MLX42_DIR   = MLX42
MLX42_LIB   = $(MLX42_DIR)/build/libmlx42.a

INCLUDE    = -I$(MLX42_DIR)/include -I header -I libft
LDINCLUDE	= -L$(MLX42_DIR)/build -lmlx42 -L$(LIBFTDIR) -lft -lglfw -framework Cocoa -framework OpenGL -framework IOKit
CFLAGS		= -Wextra -Wall -Werror -g $(INCLUDE)

SRCS	= 	src/main.c src/images.c src/utils.c src/images2.c src/check.c src/path_check.c src/map.c get_next_line/get_next_line.c \
			src/up.c src/down.c src/left.c src/right.c src/clear.c \

BONUS	=	bonus/main.c bonus/images.c bonus/utils.c bonus/images2.c bonus/check.c bonus/path_check.c bonus/monster.c \
			bonus/up.c bonus/down.c bonus/left.c bonus/right.c bonus/clear.c bonus/map.c get_next_line/get_next_line.c \
			bonus/monster_2.c \

BNS_OBJS := ${BONUS:.c=.o}

OBJS	:= ${SRCS:.c=.o}

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFTDIR) && make clean -C $(LIBFTDIR)

$(MLX42_DIR):
			git clone $(MLX42_URL) $(MLX42_DIR)

$(MLX42_LIB):	$(MLX42_DIR)
			cd $(MLX42_DIR) && cmake -B build && cmake --build build

$(NAME):	$(MLX42_LIB) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDINCLUDE) -o $(NAME)
	echo "$(COLOUR_BLUE)So_long compiled successfully!$(COLOUR_END)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


bonus:	$(MLX42_LIB) $(LIBFT) $(BNS_OBJS)
	$(CC) $(CFLAGS) $(BNS_OBJS) $(LDINCLUDE) -o $(NAME)
	echo "$(COLOUR_BLUE)So_long bonus compiled successfully!$(COLOUR_END)"

clean:
	$(RM) $(OBJS)
	$(RM) $(BNS_OBJS)
	rm -rf $(MLX42_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFTDIR)
	echo "$(COLOUR_BLUE)So_long cleaned successfully!$(COLOUR_END)"
	echo "$(COLOUR_GREEN)MLX42 cleaned successfully!$(COLOUR_END)"

re: clean all

.PHONY: all clean fclean re