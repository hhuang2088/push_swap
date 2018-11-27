NAME = push_swap
PS_HEADER = ./inc/
PSDIR = ./src/
FLAGS = -g -Wall -Wextra -Werror
CC = gcc
PS_FILES = main.c ps_util.c solver.c set_util.c util.c \
					value_functions.c solver_util.c apply_optimal_rotation.c \
					populate_listb.c partition_util.c populate_listb_util.c \
					optimized_sb.c repopulate_lista.c process_argv.c \
					apply_rotation.c fill_partition_a_and_b.c \
					ch_get_input_tokens.c
LIBDIR = ../libft/
LIBFT = $(LIBDIR)libft.a
LIBLINK = -L$(LIBDIR) -lft
PS_OPTIONS = -I$(PS_HEADER) $(FLAGS)
PRINTF = ../ft_printf/ft_printf.a
PFDIR = ../ft_printf
PFLINK = -L$(PFDIR) -lftprintf
PS_STACK_DIR = ../ps_stack/
PS_STACK = $(PS_STACK_DIR)ps_stack.a
PS_STACK_LINK = -L$(PS_STACK_DIR) -lps_stack
AR = ar rc
PS = $(addprefix $(PSDIR), $(PS_FILES))
PSOBJ = $(PS_FILES:.c=.o)

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
	make -C $(PS_STACK_DIR)

main.o: $(PSDIR)main.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)main.c

process_argv.o: $(PSDIR)process_argv.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)process_argv.c

ps_util.o: $(PSDIR)ps_util.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)ps_util.c

solver.o: $(PSDIR)solver.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)solver.c

set_util.o: $(PSDIR)set_util.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)set_util.c

util.o: $(PSDIR)util.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)util.c

value_functions.o: $(PSDIR)value_functions.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)value_functions.c

solver_util.o: $(PSDIR)solver_util.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)solver_util.c

partition_util.o: $(PSDIR)partition_util.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)partition_util.c

apply_rotation.o: $(PSDIR)apply_rotation.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)apply_rotation.c

apply_optimal_rotation.o: $(PSDIR)apply_optimal_rotation.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)apply_optimal_rotation.c

populate_listb.o: $(PSDIR)populate_listb.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)populate_listb.c

populate_listb_util.o: $(PSDIR)populate_listb_util.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)populate_listb_util.c

fill_partition_a_and_b.o: $(PSDIR)fill_partition_a_and_b.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)fill_partition_a_and_b.c

repopulate_lista.o: $(PSDIR)repopulate_lista.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)repopulate_lista.c

optimized_sb.o: $(PSDIR)optimized_sb.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)optimized_sb.c

ch_get_input_tokens.o: $(PSDIR)ch_get_input_tokens.c $(PS_HEADER)pushswap.h
	$(CC) $(PS_OPTIONS) -c $(PSDIR)ch_get_input_tokens.c

$(NAME): $(PSOBJ)
	$(CC) $(LIBLINK) $(PFLINK) $(PS_STACK_LINK) $(PSOBJ) -o $(NAME)

clean:
	rm -f $(PSOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
