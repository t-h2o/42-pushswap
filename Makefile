#	Compilation setting

NAME	=	push_swap	

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
#OFLAGS	=	-fsanitize=address


#	Headers

DIR_INC	=	./headers/
HEADER	=	pushswap.h


#	Sources

DIR_SRC	=	./srcs
SRCS	=	${DIR_SRC}/main.c		\
			${DIR_SRC}/ps_array.c	\
			${DIR_SRC}/ps_print.c	\
			${DIR_SRC}/ps_error.c	\
			${DIR_SRC}/ps_scan.c	\
			${DIR_SRC}/ps_sort.c	\
			${DIR_SRC}/ps_quick.c	\
			${DIR_SRC}/ps_split.c	\
			${DIR_SRC}/ps_function.c



#	Objets

DIR_OBJ	=	./objs
OBJS	=	${addprefix ${DIR_OBJ}/, ${notdir ${SRCS:.c=.o}}}

#	Linux
ifeq ($(UNAME_S),Linux)
	@echo "It is linux os"
endif


#	Apple
ifeq ($(UNAME_S),Darwin)
	@echo "It is mac os"
endif

RM		=	rm -f

vpath %.c ${DIR_SRC}


all : ${NAME}

${NAME}:	${OBJS}
	${CC} ${OFLAGS} ${OBJS} -o ${NAME}

${DIR_OBJ}/%.o : %.c | ${DIR_OBJ}
	${CC} ${CFLAGS} -I ${DIR_INC} -o $@ -c $^

${DIR_OBJ} :
	@mkdir -p ${DIR_OBJ}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

norm:
	norminette ${DIR_INC}${HEADER} ${SRCS}

lldb:
	gcc ${SRCS} -I${DIR_INC} -g -o ${NAME}
	lldb ${NAME}

visual:
	make
	cp push_swap push_swap_visualizer/
	python3 push_swap_visualizer/pyviz.py 0 6 1 9 4 8 7 5 2 3
