
#include "get_next_line.h"
size_t	ft_strlen(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*res;

	if (count && size > SIZE_MAX / count)
		return (0);
	res = (char *)malloc(count * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count * size)
		res[i++] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	if (len >= s_len - start)
		len = s_len - start;
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && start + i < s_len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}


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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	if (!dst && !dstsize)
		return (src_len);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize <= dst_len || dstsize == 0)
		return (src_len + dstsize);
	while (i < dstsize - dst_len - 1 && i < src_len)
	{
		dst[(dst_len + i)] = src[i];
		i++;
	}
	dst[(dst_len + i)] = '\0';
	return (src_len + dst_len);
}



char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	size_t	s1_len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1) + 1;
	total_len = s1_len + ft_strlen(s2);
	res = (char *)ft_calloc(total_len, sizeof(char));
	if (!res)
		return (NULL);
    
	ft_strlcat(res, s1, s1_len);
	ft_strlcat(res, s2, total_len);
	return (res);
}

char *ft_cut_line(char *line,ssize_t start)
{
    char *res;
    ssize_t i;

 	res = ft_calloc(start + 1 ,sizeof(char));
	if (!res)
		return NULL;
	ft_strlcat(res,line,start + 1);
    i = 0;
    while ( line[start + i] )
    {
		line[i] = line[start + i];
		line[start + i] = 0;
        i++; 
    }
	return  res;
}

char *get_next_line(int fd)
{
    static file_t read_file;
	ssize_t nl_index;
	if (!read_file.line)
		read_file.line = ft_calloc(1,sizeof(char));
    read_file.buffer = ft_calloc(BUFFER_SIZE + 1 ,sizeof(char));
	if (!read_file.line || ! read_file.buffer)
		return NULL;
	read_file.bytes_read = read(fd,read_file.buffer,BUFFER_SIZE);
    while ( read_file.bytes_read >= 0 || read_file.line)
    {
        read_file.line = ft_strjoin(read_file.line ,read_file.buffer);
        nl_index = ft_strchr_index(read_file.line,'\n');
        if ( nl_index >= 0)
		{
			free(read_file.buffer);
			return ft_cut_line(read_file.line,nl_index + 1);
		}
		else if ( read_file.bytes_read < BUFFER_SIZE)
		{
			free(read_file.buffer);
            return read_file.line;
		}
		read_file.bytes_read = read(fd,read_file.buffer,BUFFER_SIZE);
    }
    return NULL;
}

int main()
{
    int fd = open("./text.txt",O_RDWR);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	// get_next_line(fd);
	// get_next_line(fd);
    close(fd);
}
