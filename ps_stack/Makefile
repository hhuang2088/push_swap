NAME = libps_stack.a
HEADER = ./inc/
HEADER_FILE = $(HEADER)ps_stack.h $(LIBHEAD)
SRCDIR = ./src/
LIBDIR = ../libft/
LIBHEAD = $(LIBDIR)libft.h
LIB = $(LIBDIR)libft.a
LIBINC = -I$(LIBDIR)
LIBLINK = -L$(LIBDIR) -lft
FLAGS = -g -Wall -Wextra -Werror -c
CC = gcc
FLAGS_TEST = -g -c
OPTIONS = -I$(HEADER) $(FLAGS)
COMPILE = $(CC) $(OPTIONS)
SRC_FILES = ps_stack.c
AR = ar rc
SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
FILES = $(SRC_FILES)
OBJ_NAME = $(FILES:.c=.o)
RLIB = ranlib

.PHONY: all clean fclean re

all: libft $(NAME)

libft: $(LIB)

$(LIB):
	make -C $(LIBDIR)
	$(COMPILE) $(LIBLINK)

ps_stack.o: $(SRCDIR)ps_stack.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ps_stack.c

$(NAME): $(OBJ_NAME)
	$(AR) $(NAME) $(OBJ_NAME)
	$(RLIB) $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

cleantest:
	rm -f test.o
	rm -f hello

re: fclean all
