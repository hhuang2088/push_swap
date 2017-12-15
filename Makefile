# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 16:10:11 by hehuang           #+#    #+#              #
#    Updated: 2017/12/14 16:12:34 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PS = ./ps/push_swap
CH = ./ch/checker

PSDIR = ./ps/
CHDIR = ./ch/

.PHONY: all clean

all: ps ch $(NAME)

libft: $(LIBFT)

ps: $(PS)

ch: $(CH)

$(PS):
	make -C $(PSDIR)

$(CH):
	make -C $(CHDIR)

$(NAME):
	cp $(PSDIR)push_swap ./
	cp $(CHDIR)checker ./

clean:
	rm checker
	rm push_swap
