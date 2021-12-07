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
		split.c\
		ultrafunctionfile.c
SRC_BONUS = ft_strncmp.c \
		listlibftmofified.c\
		pipex.fun.c\
		pipex_mon.c\
		ft_strcmp.c\
		get_next_line.c\
		main_bonus.c\
		pipexdel.c\
		ft_strjoin.c\
		get_next_line_utils.c\
		pipex.c\
		pipex_bonus2_utils.c\
		split.c\
		ultrafunctionfile.c
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME): $(INCLUDE) $(SRC:.c=.o)
	@gcc $(CFLAGS) $(SRC) -I $(INCLUDE) -o $(NAME)
bonus: $(INCLUDE) $(SRC_BONUS:.c=.o)
	gcc $(CFLAGS) $(SRC_BONUS) -I $(INCLUDE) -o $(NAME)
clean:
	rm -f $(SRC:.c=.o) $(SRC_BONUS:.c=.o)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re $(NAME)