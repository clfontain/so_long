# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:32:38 by palbanes          #+#    #+#              #
#    Updated: 2022/07/20 10:44:03 by cfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

LIB_DIR		= ./libft

MLX_DIR 	= ./minilibx-linux

LIBFT		= ./libft/libft.a

MLX		= ./minilibx-linux/libmlx.a

SRCS		= main.c init_image.c map_parsing.c map_parsing_2.c map_parsing_3.c hide.c display.c move.c move_mob.c where_is_waldo.c key_and_end.c animation.c

OBJS		= ${SRCS:.c=.o}

RM		= rm -f

CC		= gcc

FLAGS		= -Wall -Wextra -Werror -g3

FLAGS_LIB	= -lXext -lX11

all		: ${NAME}

.c.o		:
		  @${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${LIBFT}	:
		  @echo "\033[35m----Building libft----"
		  @make -sC ${LIB_DIR}
		  @echo "OK"

${MLX}		:
		  @echo "\033[35m----Building MLX----"
		  @make -sC ${MLX_DIR}
		  @echo "OK"

${NAME}		: ${OBJS} ${LIBFT} ${MLX}
		  @echo "\033[34m----Compiling----"
		  @${CC} ${FLAGS} ${OBJS} -L ${MLX_DIR} -lmlx -lm ${FLAGS_LIB} -o ${NAME} ${LIBFT} 
		  @echo "OK"

clean		:
		  @echo "\033[31m----Cleaning libft----"
		  @make clean -sC ${LIB_DIR}
		  @echo "OK"
		  @echo "\033[31m----Cleaning MLX----"
		  @make clean -sC ${MLX_DIR}
		  @echo "OK"
		  @echo "\033[31m----Cleaning objects----"
		  @${RM} ${OBJS}
		  @echo "OK"

fclean		: clean
		  @echo "\033[33m----Cleaning all----"
		  @${RM} ${NAME}
		  @${RM} ${LIBFT}
		  @${RM} ${MLX}
		  @echo "OK"

re		: fclean all

.PHONY		: all clean fclean re
