C_FILES = get_next_line.c get_next_line_utils.c

OBJS = ${patsubst %.c,%.o,$(C_FILES)}

CC = cc
 
HEADERS = -I=get_next_line.h

FLAGS = -Wall -Werror -Wextra $(HEADERS)

NAME = get_next_line

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $^

all : $(NAME)

libft.a : 
	cd libft ; make ; make clean

$(NAME) : libft.a $(OBJS)
	$(CC) -o $(NAME) $(OBJS) libft/libft.a

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re libft.a