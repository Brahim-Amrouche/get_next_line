C_FILES = get_next_line.c get_next_line_utils.c

OBJS = ${patsubst %.c,%.o,$(C_FILES)}

CC = cc
 
HEADERS = -I=get_next_line.h


CFLAGS = -Wall -Werror -Wextra -fsanitize=address $(HEADERS) -D BUFFER_SIZE=2

NAME = get_next_line

%.o : %.c
	$(CC) $(CFLAGS) -c $?  -o $@

all : $(NAME)

$(NAME) : libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re libft.a