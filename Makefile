NAME		:= fractol
NAME_BONUS	:= fractol_bonus

CFLAGS	:= -Wall -Wextra -Werror -MMD -MP -Ofast
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS		:=	hooks.c	\
				inits.c	\
				main.c	\
				sets.c	\
				utils.c	\
				sierpinsky.c	\
				drawing_tools.c

SRCS_BONUS	:=	hooks_bonus.c	\
				inits_bonus.c	\
				main_bonus.c	\
				sets_bonus.c	\
				utils_bonus.c	\
				sierpinsky_bonus.c	\
				drawing_tools_bonus.c	\
				hooks_pinsky_bonus.c

SRCS_PATH		:= $(addprefix ./src/,$(SRCS))
SRCS_BONUS_PATH	:= $(addprefix ./src_bonus/,$(SRCS_BONUS))

OBJS		:= ${SRCS_PATH:.c=.o}
OBJS_BONUS	:= ${SRCS_BONUS_PATH:.c=.o}

DEP			= $(OBJS:.o=.d)
DEP_BONUS	= $(OBJS_BONUS:.o=.d)

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

-include $(DEP)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

-include $(DEP_BONUS)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@rm -rf $(DEP) $(DEP_BONUS)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)

re: clean all

reb: clean bonus

.PHONY: all, clean, fclean, re, reb, libmlx, bonus