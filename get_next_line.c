/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:23:00 by bamrouch          #+#    #+#             */
/*   Updated: 2022/10/28 02:09:41 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_cut_line(char **line, ssize_t len)
{
	char	*res;
	char	*temp;

	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcat(res, *line, len + 1);
	temp = *line;
	*line = ft_substr(*line, len, ft_strlen((*line) + len));
	free(temp);
	return (res);
}

char	*get_next_line_helper(int fd, char *buffer, char **line)
{
	ssize_t	bytes_read;
	ssize_t	nl_index;
	ssize_t	i;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read >= 0 || *line)
	{
		i = 0;
		*line = ft_strjoin((*line), buffer);
		while (buffer[i])
			buffer[i++] = 0;
		nl_index = ft_strchr_index(*line, '\n');
		if (nl_index >= 0)
			return (ft_cut_line(line, nl_index + 1));
		else if (bytes_read < BUFFER_SIZE)
			return (ft_strjoin((*line), ""));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (ft_strjoin((*line), ""));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*res;

	if (!line)
		line = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line || !buffer)
		return (NULL);
	res = get_next_line_helper(fd, buffer, &line);
	free(buffer);
	if (ft_strchr_index(res, '\n') == -1)
	{
		free(line);
		line = NULL;
	}
	return (res);
}

int	main(void)
{
	int	fd;

	fd = open("./text.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
