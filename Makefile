NAME		:= fractol
NAME_BONUS	:= fractol_bonus

CFLAGS	:= -Ofast
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	:=	./src/hooks.c	\
			./src/inits.c	\
			./src/main.c	\
			./src/sets.c	\
			./src/utils.c

SRCS_BONUS	:=	./src/hooks_bonus.c	\
				./src/inits_bonus.c	\
				./src/main_bonus.c	\
				./src/sets_bonus.c	\
				./src/utils_bonus.c	\
				./src/sierpinsky_bonus.c	\
				./src/drawing_tools_bonus.c

OBJS		:= ${SRCS:.c=.o}
OBJS_BONUS	:= ${SRCS_BONUS:.c=.o}


all: libmlx $(NAME)

bonus: libmlx $(NAME_BONUS)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -sC $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf "Compiling: $(notdir $<) \n"

$(NAME): $(OBJS) 
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)

re: clean all

reb: clean bonus

.PHONY: all, clean, fclean, re, reb, libmlx, bonus