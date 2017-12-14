NAME = push_swap
PS = ./ps/push_swap
CH = ./ch/checker
PSDIR = ./ps/
CHDIR = ./ch/

.PHONY: all clean

all: ps ch $(NAME)

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
