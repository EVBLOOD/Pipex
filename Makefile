NAME = pipex
INCLUDE = pipex.h
SRC = ft_strncmp.c \
		listlibftmofified.c\
		pipex.fun.c\
		pipex_mon.c\
		ft_strcmp.c\
		get_next_line.c\
		main.c\
		pipexdel.c\
		ft_strjoin.c\
		get_next_line_utils.c\
		pipex.c\
		pipex_bonus2_utils.c\
		split.c

CFLAGS = -Wall -Werror -Wextra
.PHONY: all clean fclean re $(NAME)
all: $(NAME)
$(NAME): $(INCLUDE) $(SRC)
	gcc $(CFLAGS) $(SRC) -I $(INCLUDE) -o $(NAME)
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME)
re: fclean all