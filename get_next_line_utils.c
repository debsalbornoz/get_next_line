/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:52:08 by dlamark-          #+#    #+#             */
/*   Updated: 2023/06/10 16:57:04 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/* Concatenates two strings into a new string. It calculates the length of the resulting string, allocates memory for it,
and then copies the characters from s1 and s2 into s3. The function returns a pointer to the newly created string s3*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s3_len;
	char	*s3;
	int		i;
	int		j;

	i = 0;
	s3_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((s3_len + 1) * sizeof(char));
	if (!s3 || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[s3_len] = '\0';
	return (s3);
}

/*Searches for the first occurrence of a specified character in a given string.
If the character is found, it returns a pointer to the located character within the string.*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
	{
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

//Sets the first n bytes of the memory block pointed to by s to zero

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

//Allocates a block of memory for an array, initializing all its bytes to zero.

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	total;

	str = NULL;
	total = size * nmemb;
	if (total != 0 && total / size != nmemb)
		return (NULL);
	str = malloc(total);
	if (!str)
		return (NULL);
	ft_bzero(str, total);
	return (str);
}

//Calculates and returns the length of a given string 

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
