
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#   include <stdio.h>
#   include <unistd.h>
#   include <sys/types.h>
#   include <sys/stat.h>
#   include <fcntl.h>
#   include "libft/libft.h"
#   define BUFFER_SIZE 16

typedef struct file_s
{
    ssize_t bytes_read;
    void *buffer;
} file_t;




#endif