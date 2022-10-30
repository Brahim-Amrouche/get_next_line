C_FILES = get_next_line.c get_next_line_utils.c

BONUS_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = ${patsubst %.c,%.o,$(C_FILES)}

B_OBJS = ${patsubst %.c,%.o,$(BONUS_FILES)}

CC = cc
 
HEADERS = -I=get_next_line.h


CFLAGS = -Wall -Werror -Wextra -fsanitize=address $(HEADERS) -D BUFFER_SIZE=2

NAME = get_next_line

%.o : %.c
	$(CC) $(CFLAGS) -c $?  -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(NAME) 

.PHONY : all clean fclean re libft.a