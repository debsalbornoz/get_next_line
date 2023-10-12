/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:37:26 by dlamark-          #+#    #+#             */
/*   Updated: 2023/06/10 19:07:36 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "get_next_line.h"

char	*join_and_free(char *buffer, char *buf);
char	*store_memory(char *buffer);
char	*ft_get_line(char *buffer);
char	*read_line_break(int fd, char *res);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
