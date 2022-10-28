/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:29:33 by bamrouch          #+#    #+#             */
/*   Updated: 2022/10/28 01:16:05 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

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

ssize_t	ft_strchr_index(const char *s, int c)
{
	char	*temp;
	ssize_t	i;

	temp = (char *)s;
	i = 0;
	while (*(temp + i))
	{
		if (*(temp + i) == (char)c)
			return (i);
		i++;
	}
	return (-1);
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
