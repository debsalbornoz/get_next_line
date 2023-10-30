/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:55:38 by dlamark-          #+#    #+#             */
/*   Updated: 2023/06/10 19:05:57 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Main function to get the next line from the file
char	*get_next_line(int fd)
{
	static char	*memory; // Static variable to store leftover data between function calls
	char		*line;   // Variable to store the current line read from the file

	// Validity checks for file descriptor (fd) and buffer size
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	
	// Read the line until a newline character is found and store the remaining data in 'memory'
	memory = read_line_break(fd, memory);
	if (!memory)
		return (NULL);
	
	// Get the current line and update 'memory' to store the remaining data
	line = ft_get_line(memory);
	memory = store_memory(memory);
	
	return (line);
}

// Function to read until a newline character is found or end of file is reached
char	*read_line_break(int fd, char *memory)
{
	char	*buffer; 
	int		byte_read;

	if (!memory)
		memory = ft_calloc(1, 1); // Allocate memory for 'memory' if it's not initialized
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); // Allocate memory for the buffer
	byte_read = 1;

	// Read characters from the file into the buffer until a newline character is found or end of file is reached
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0'; // Null-terminate the buffer
		memory = join_and_free(memory, buffer); // Concatenate buffer with existing 'memory'
		if (ft_strchr(buffer, '\n')) // Check if newline character is present in the buffer
			break; // Exit the loop if newline character is found
	}
	free(buffer); // Free the buffer memory after reading is done
	return (memory); // Return the concatenated data (including the current line)
}

// Function to concatenate two strings and free the memory of the old string
char	*join_and_free(char *memory, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(memory, buffer); // Concatenate 'memory' and 'buffer' into 'temp'
	free(memory); // Free the old 'memory'
	return (temp); // Return the concatenated string
}

// Function to get the current line from the memory and return it
char	*ft_get_line(char *memory)
{
	char	*line;
	int		i;

	i = 0;

	// Allocate memory for 'line' based on the length of the current line
	line = ft_calloc(i + 2, sizeof(char));

	// Copy characters from 'memory' to 'line' until a newline character is found
	while (memory[i] && memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] && memory[i] == '\n')
		line[i++] = '\n'; // Add newline character to 'line' if it's present in 'memory'
	line[i++] = '\0'; // Null-terminate 'line'
	return (line); // Return the current line
}

// Function to store the remaining data in 'memory' after the current line
char	*store_memory(char *memory)
{
	int		i;
	int		j;
	char	*line;

	i = 0;

	// Find the index where the newline character is located in 'memory'
	while (memory[i] && memory[i] != '\n')
		i++;

	// If there is no newline character, free 'memory' and return NULL
	if (!memory[i])
	{
		free(memory);
		return (NULL);
	}

	// Allocate memory for 'line' based on the remaining data length in 'memory'
	line = ft_calloc((ft_strlen(memory) - i + 1), sizeof(char));

	i++;

	j = 0;

	// Copy the remaining data from 'memory' to 'line'
	while (memory[i])
		line[j++] = memory[i++];

	free(memory); // Free 'memory' as it's no longer needed
	return (line); // Return the remaining data (after the current line) as 'line'
}

