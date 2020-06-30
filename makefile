SRCS		= printf.c printf_regex.c printf_utils.c printf_validations.c printf_config_validations.c printf_args.c printf_args2.c printf_args3.c printf_args4.c strucs_initialize.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd libft && ${MAKE}
			cp libft/libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJ_BONUS}
			${MAKE} clean -C ./libft

fclean : 	clean
			${RM} ${NAME}
			${RM} libft.a
			${MAKE} fclean -C ./libft

re:			fclean all

.PHONY:		re all clean fclean
