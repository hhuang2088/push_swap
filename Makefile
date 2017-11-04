NAME = checker
CH_HEADER = ./ch/inc/
CHDIR = ./ch/src/
FLAGS = -Wall -Wextra -Werror
CC = gcc
CH_FILES = main.c checker.c checker_commands1.c checker_util.c
LIBDIR = ./libft/
LIBFT = $(LIBDIR)libft.a
LIBLINK = -L$(LIBDIR) -lft
CH_OPTIONS = -I$(CH_HEADER) $(FLAGS)
PRINTF = ./ft_printf/ft_printf.a
PFDIR = ./ft_printf
PFLINK = -L$(PFDIR) -lftprintf
AR = ar rc
CH = $(addprefix $(CHDIR), $(CH_FILES))
CHOBJ = $(CH_FILES:.c=.o)

.PHONY: all clean fclean re

all: libft printf $(NAME)

libft: $(LIBFT)

printf: $(PRINTF)

$(LIBFT):
	make -C $(LIBDIR)

$(PRINTF):
	make -C $(PFDIR)

main.o: $(CHDIR)main.c $(CH_HEADER)checker.h
	 $(CC) $(CH_OPTIONS) -c $(CHDIR)main.c

checker.o: $(CHDIR)checker.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)checker.c

checker_commands1.o: $(CHDIR)checker_commands1.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)checker_commands1.c

checker_util.o: $(CHDIR)checker_util.c $(CH_HEADER)checker.h
	$(CC) $(CH_OPTIONS) -c $(CHDIR)checker_util.c

checker: $(CHOBJ)
	$(CC) $(LIBLINK) $(PFLINK) $(CHOBJ) -o checker

clean:
	rm -f $(CHOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
