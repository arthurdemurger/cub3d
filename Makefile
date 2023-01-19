# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 11:29:10 by ademurge          #+#    #+#              #
#    Updated: 2023/01/15 17:58:43 by ademurge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

# Name of the executable
NAME						=	cub3d

NAME_TEST					=	cub3d_test

# Files
SRC							=	src/check.c \
								src/error.c \
								src/free.c \
								src/main.c \
								src/parse.c \
								src/DDA.c \
								src/gnl/get_next_line.c \
								src/gnl/get_next_line_utils.c \
								src/utils/parse_utils.c \
								src/tests/tests.c

SRC_TEST					=	src/tests/tests.c

LIBFT_LINUX					=	src/libft/lst/ft_lst_to_tab.c \
								src/libft/lst/ft_lstadd_back.c \
								src/libft/lst/ft_lstclear.c \
								src/libft/lst/ft_lstdelone.c \
								src/libft/lst/ft_lstget.c \
								src/libft/lst/ft_lstindex.c \
								src/libft/lst/ft_lstlast.c \
								src/libft/lst/ft_lstnew.c \
								src/libft/lst/ft_lstput.c \
								src/libft/lst/ft_lstsize.c \
								src/libft/ft_putendl_fd.c \
								src/libft/ft_putstr.c \
								src/libft/ft_puttab.c \
								src/libft/ft_split_charset.c \
								src/libft/ft_split.c \
								src/libft/ft_strchr.c \
								src/libft/ft_strcmp.c \
								src/libft/ft_strlcpy.c \
								src/libft/ft_strncmp.c \
								src/libft/ft_strstr.c \
								src/libft/ft_strtrim.c \
								src/libft/ft_substr.c \
								src/libft/ft_tablen.c \
								src/libft/ft_bzero.c \
								src/libft/ft_strcpy.c \
								src/libft/lst/ft_lstmax.c

LIBFT						=	./src/libft/libft.a

INC							=	-I ./inc/.

INC_TEST					=	-I ./inc/test/.

OBJS						=	$(SRC:.c=.o)

# Flags
CFLAGS						=	-Wall -Wextra -Werror

RM							=	rm -rf

CC							=	gcc

LMLX_LINUX					=	-lmlx -lXext -lX11

LMLX_MAC					=	-lmlx -L ./files/mlx -framework OpenGL -framework AppKit

# Rules
all: 		libft $(NAME)

%o:				%c
				@$(CC) ${CFLAGS} -I./includes -c $< -o ${<:.c=.o}

test:
				@$(CC) $(CFLAGS) $(INC_TEST) $(SRC_TEST) $(LMLX_LINUX) -lm -o $(NAME_TEST)
				@echo "$(GREEN)********** Compiled. $(RESET)"

linux:
				@$(CC) $(CFLAGS) $(INC) $(SRC_LINUX) $(LMLX_LINUX) -lm -o $(NAME)
				@echo "$(GREEN)********** Compiled. $(RESET)"

$(NAME): libft $(OBJS)
					@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) $(LMLX_MAC) -o $(NAME)
					@echo "$(GREEN)********** Compiled. $(RESET)"

libft:
					@make -C ./src/libft

clean:
					@$(RM) $(OBJS)
					@make clean -C ./src/libft
					@echo "$(PURPLE)********* Objects removed. $(RESET)"

fclean: clean
			@$(RM) $(NAME)
			@$(RM) $(NAME_TEST)
			@$(RM) $(LIBFT)
			@echo "$(LIGHTPURPLE)********* Executable removed. $(RESET)"

re: fclean all

.PHONY: all clean fclean re libft