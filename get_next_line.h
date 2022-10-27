
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct file_s
{
	ssize_t	bytes_read;
	void	*buffer;
    void    *line;
}			file_t;

#endif