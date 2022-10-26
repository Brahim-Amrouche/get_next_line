
#include "get_next_line.h"

ssize_t ft_strchr_index(const char *s, int c)
{
	char	*temp;
    ssize_t i;

	temp = (char *)s;
    i = 0;
	while (*(temp + i))
	{
		if (*(temp + i) == (char)c)
			return i;
		i++;
	}
	return (-1);
}


char *get_next_line(int fd)
{
    static file_t read_file;
    char *line;
    ssize_t nl_index;
    line = ft_calloc(1,sizeof(char));
    read_file.buffer = ft_calloc(BUFFER_SIZE + 1 ,sizeof(char));
    if (!read_file.buffer)
        return NULL;
    while ((read_file.bytes_read = read(fd,read_file.buffer,BUFFER_SIZE)) >= 0)
    {
        nl_index = ft_strchr_index(read_file.buffer,'\n');    
        if ( nl_index >= 0)
        {
            line = ft_strjoin(line, ft_substr(read_file.buffer, 0, nl_index + 1));
            return line;
        }
        else if (nl_index == -1  && read_file.bytes_read == BUFFER_SIZE )
            line = ft_strjoin(line , read_file.buffer);
        else if ( read_file.bytes_read < BUFFER_SIZE)
        {
            line = ft_strjoin(line,read_file.buffer);
            return line;
        }
    }
    return line;
}

int main()
{
    int fd = open("./text.txt",O_RDWR);
    printf("|%s| is this a new line \n",get_next_line(fd));
    printf("|%s| is this a new line \n",get_next_line(fd));
    close(fd);
}