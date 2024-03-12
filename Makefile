# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 20:42:17 by juhaamid          #+#    #+#              #
#    Updated: 2024/03/07 17:47:06 by ansulist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	cub3D

SRCS	=	cub3d.c \
			load_map.c \
			key.c \
			load_map_utils.c \
			load_map2.c \
			load_color.c \
			load_path_texture.c \
			texture.c \
			chcking_line.c \
			raycast.c \
			ray_calculation.c \
			raycast_helper.c \
			draw_utils.c \
			get_map_to_array.c \
			key_moves.c \
			keyhandler.c \
			get_map_to_arr_utils.c \
			get_ma_array_utils2.c \
			check_init.c \

GNLSRCS = ./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	include

LB	=	./libft/libft.a

CC		=	cc

OS:= ${shell uname}
ifeq (${OS},Darwin)
	MLXDIR = mlx
	MLXFLG = -framework OpenGL -framework Appkit
	CFLAGS += -D OSX -Wall -Werror -Wextra
else
	MLXDIR = mlx_linux
	MLXFLG = -lXext -lX11
	CFLAGS += -D LINUX
 endif

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

all:	${LB} ${NAME} ${MLXDIR}

${NAME}:	${OBJS}
			make -C $(MLXDIR)
			${CC} ${CFLAGS} ${OBJS} ${GNLSRCS} -L${MLXDIR} -lmlx -march=native ${MLXFLG} ${LB} -o ${NAME} -lm

$(LB):	
			${MAKE} -C ./libft
# $(MLXDIR):		
# 			${MAKE} -C ${MLXDIR}


clean:		
			rm -f ${OBJS}
			${MAKE} clean -C  $(MLXDIR) 
			${MAKE} fclean -C  ./libft

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
