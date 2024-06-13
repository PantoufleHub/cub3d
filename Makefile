NAME		=	cub3D

INC_DIR		=	inc/
SRC_DIR		=	src/
SRC_SUBDIRS	=	main
OBJ_DIR		=	obj/
DEP_DIR		=	$(OBJ_DIR)dep/
LIBFT_DIR	=	lib/libft/
# MLX_DIR		=	lib/mlx/
MLX_DIR		=	lib/minilibx-linux/
MAIN_SRCS	=	main

ifeq ($(MAIN), tim)
	MAIN_SRCS = main_tim
else ifeq ($(MAIN), alexis)
	MAIN_SRCS = main_alexis
endif
 
SRCS		=	$(addprefix $(SRC_DIR)main/, $(addsuffix .c, $(MAIN_SRCS)))
OBJS		=	$(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
DEPS		=	$(addprefix $(DEP_DIR), $(notdir $(SRCS:.c=.d)))
VPATH		=	$(addprefix $(SRC_DIR), $(SRC_SUBDIRS))
vpath %.c $(VPATH)

LIBFT		=	$(LIBFT_DIR)libft.a
MLX			=	$(MLX_DIR)libmlx.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
DEP_FLAGS	=	-MMD -MP -MF $(DEP_DIR)$*.d
RM			=	rm -f

DEF_COLOR	=	\033[0;39m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m

ifeq ($(MODE), debug)
	CFLAGS += -g
else ifeq ($(MODE), sanitize)
	CFLAGS += -g -fsanitize=address
endif

all:			$(NAME)

# @$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -Llib/mlx -lm -lmlx -framework OpenGL -framework AppKit -o $@
$(NAME): $(LIBFT) $(OBJS) $(MLX)
				$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -Llib/minilibx-linux/ -lm -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@
				@printf "$(GREEN)\n$(NAME) successfully compiled$(DEF_COLOR)\n"

$(OBJ_DIR)%.o:	%.c
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(DEP_DIR)
				$(CC) $(CFLAGS) $(DEP_FLAGS) -Ilib/minilibx-linux/ -I $(INC_DIR) -I$(LIBFT_DIR)/inc -c $< -o $@
				@printf "$(YELLOW).$(DEF_COLOR)"

$(LIBFT):
				@make -C $(LIBFT_DIR) MODE=$(MODE)

$(MLX):
				@make -C $(MLX_DIR) all
clean:
				@$(RM) -r $(OBJ_DIR)
				@make -C $(LIBFT_DIR) clean
				@make -C $(MLX_DIR) clean

fclean:			clean
				@$(RM) $(NAME)
				@make -C $(LIBFT_DIR) fclean

re:				fclean all

-include $(DEPS)

.PHONY:			all clean fclean re
