# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 13:19:16 by tfrily            #+#    #+#              #
#    Updated: 2024/02/06 15:07:34 by tfrily           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
INC_DIR		=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
SRC_SUBDIRS  =   ft_printf gnl libft
DEP_DIR		=	$(OBJ_DIR)dep/
LIBFT_DIR	=	$(SRC_DIR)/libft/
PRINTF_DIR	=	$(SRC_DIR)/ft_printf/
GNL_DIR		=	$(SRC_DIR)/gnl/

SRC			= ft_isalnum  ft_isalpha ft_isdigit ft_isprint ft_isascii ft_strlen \
			  ft_memset ft_bzero ft_memcpy ft_calloc ft_memmove ft_strlcpy ft_strlcat ft_toupper \
			  ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr \
			  ft_atoi ft_strdup ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_substr ft_strjoin \
			  ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putnbr_fd ft_lstnew_bonus ft_lstadd_front_bonus  \
			  ft_lstsize_bonus ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus \
			  ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus ft_clean ft_clean2dtable

FT_PRINTFSRC	=  ft_char_convertion ft_convert_hex ft_digit_convertion ft_printf

GNLSRC = get_next_line get_next_line_utils

SRCS		=	$(addprefix $(LIBFT_DIR), $(addsuffix .c, $(SRC))) \
				$(addprefix $(PRINTF_DIR), $(addsuffix .c, $(FT_PRINTFSRC))) \
				$(addprefix $(GNL_DIR), $(addsuffix .c, $(GNLSRC))) \

OBJS		=	$(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
DEPS		=	$(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.d)))
VPATH		=	$(addprefix $(SRC_DIR), $(SRC_SUBDIRS))

vpath %.c $(VPATH)

DEP_FLAGS	=	-MMD -MF $(DEP_DIR)$*.d

LIBNAME = ft
LIBPATH = .
LIBFILE = libft.a
CC = gcc

CFLAGS = -Wall -Werror -Wextra
DEP_FLAGS	=	-MMD -MF $(DEP_DIR)$*.d
RM = /bin/rm -rf

DEF_COLOR	=	\033[0;39m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m

ifeq ($(MODE), debug)
	CFLAGS += -g
else ifeq ($(MODE), sanitize)
	CFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS) 
	@ar -rsc $(LIBFILE) $(OBJS)
	@echo "\n$(GREEN)💎Compilation libft done$(DEF_COLOR)💎"

$(OBJ_DIR)%.o:	%.c
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(DEP_DIR)
				@$(CC) $(CFLAGS) $(DEP_FLAGS) -I $(INC_DIR) -c $< -o $@
				@printf "$(YELLOW).$(DEF_COLOR)"

clean:
	 @$(RM) $(OBJ_DIR) 
	 @$(RM) $(OBJDIR)
	 @$(RM) $(wildcard $(FT_PRINTF_OBJ))
	 @$(RM) $(wildcard $(GNL_OBJ))
	 @echo "$(GREEN) 🧹Clean libft done 🧹$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFILE)
	@echo "$(GREEN) 🧹FClean libft done 🧹$(DEF_COLOR)"
re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re makedir
