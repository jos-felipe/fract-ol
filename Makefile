NAME	:= fractol
NAME_BONUS	:= fractol_bonus
CFLAGS	:= -g3
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm

SRCS	:=	./src/hooks.c	\
			./src/inits.c	\
			./src/main.c	\
			./src/sets.c	\
			./src/utils.c

SRCS_BONUS	:=	./src/hooks_bonus.c	\
				./src/inits_bonus.c	\
				./src/main_bonus.c	\
				./src/sets_bonus.c	\
				./src/utils_bonus.c

OBJS	:= ${SRCS:.c=.o}
OBJS_BONUS	:= ${SRCS_BONUS:.c=.o}


all: libmlx libft $(NAME)

bonus: libmlx libft $(NAME_BONUS)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

%.d: %.c
	@$(CC) -MM $(CFLAGS) -o $@ $<

include $(SRCS:.c=.d)

include $(SRCS_BONUS:.c=.d)

%.o: %.c $(DEPS) $(DEPS_BONUS)
	@$(CC) $(CFLAGS) -o $@ $(<:.d=.c)-c $< $(HEADERS)  && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) 
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft, bonus