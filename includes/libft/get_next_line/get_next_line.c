/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:22:15 by miovu             #+#    #+#             */
/*   Updated: 2025/01/29 20:44:13 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin1(line, buffer);
		if (!line)
			return (NULL);
		cleanbuff(buffer);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	return (line);
}

// int	main()
// {
// 	char	*line;
// 	int		fd;
// 	int		i = 0;
// 	fd = open("test3.txt", O_RDONLY);
// 	while (i < 10)
// 	{	
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 		{
// 			printf("line: %s", line);
// 			free(line);	
// 		}
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }