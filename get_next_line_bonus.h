/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:07:59 by bamrouch          #+#    #+#             */
/*   Updated: 2022/10/30 01:08:44 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

size_t	ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
ssize_t	ft_strchr_index(char *s, int c);
char	*get_next_line(int fd);

#endif