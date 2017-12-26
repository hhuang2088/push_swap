# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 13:23:52 by hehuang           #+#    #+#              #
#    Updated: 2017/12/13 13:23:55 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CH_HEADER = ./inc/
CHDIR = ./src/
FLAGS = -g -Wall -Wextra -Werror
CC = gcc
CH_FILES = main.c checker.c checker_util.c process_commands.c \
					 execution_commands.c print_lists.c checker_util2.c checker_util3.c
LIBDIR = ../libft/
LIBFT = $(LIBDIR)libft.a
LIBLINK = -L$(LIBDIR) -lft
PS_STACK_DIR = ../ps_stack/
PS_STACK_LINK = -L$(PS_STACK_DIR) -lps_stack
PS_STACK = $(PS_STACK_DIR)libps_stack.a
CH_OPTIONS = -I$(CH_HEADER) $(FLAGS)
PRINTF = ../ft_printf/ft_printf.a
PFDIR = ../ft_printf
PFLINK = -L$(PFDIR) -lftprintf
AR = ar rc
CH = $(addprefix $(CHDIR), $(CH_FILES))
CHOBJ = $(CH_FILES:.c=.o)

.PHONY: all clean fclean re

all: libft printf ps_stack $(NAME)

libft: $(LIBFT)

printf: $(PRINTF)

ps_stack: $(PS_STACK)

$(LIBFT):
	make -C $(LIBDIR)

$(PRINTF):
	make -C $(PFDIR)

$(PS_STACK):
	make - C $(PS_STACK_DIR)

checker_util.o: $(CHDIR)checker_util.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)checker_util.c

main.o: $(CHDIR)main.c $(CH_HEADER)checker.h
	 $(CC) $(CH_OPTIONS) -c $(CHDIR)main.c

checker.o: $(CHDIR)checker.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)checker.c

process_commands.o: $(CHDIR)process_commands.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)process_commands.c

execution_commands.o: $(CHDIR)execution_commands.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)execution_commands.c

print_lists.o: $(CHDIR)print_lists.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)print_lists.c

checker_util2.o: $(CHDIR)checker_util2.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)checker_util2.c

checker_util3.o: $(CHDIR)checker_util3.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)checker_util3.c

$(NAME): $(CHOBJ)
	$(CC) $(LIBLINK) $(PFLINK) $(PS_STACK_LINK) $(CHOBJ) -o $(NAME)

clean:
	rm -f $(CHOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
