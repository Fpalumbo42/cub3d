/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:05:16 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/05/07 14:14:43 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*extract(char *_line)
{
	char	*buffer;
	size_t	count;

	count = 0;
	while (!(_line[count] == '\n' || _line[count] == '\0'))
		count++;
	if (!(_line[count] != '\0' && _line[1] != '\0'))
		return (0);
	buffer = ft_substr(_line, count + 1, ft_strlen(_line) - count);
	if (*buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	_line[count + 1] = '\0';
	return (buffer);
}

char	*new_line(int _fd, char *_tmp, char *_buffer)
{
	char	*char_temp;
	int		len;

	len = 1;
	while (len != '\0')
	{
		len = read(_fd, _tmp, BUFFER_SIZE);
		if (len == -1)
			return (0);
		else if (len == 0)
			break ;
		_tmp[len] = '\0';
		if (!_buffer)
			_buffer = ft_strdup("");
		char_temp = _buffer;
		_buffer = ft_strjoin(char_temp, _tmp);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (_tmp, '\n'))
			break ;
	}
	return (_buffer);
}

char	*get_next_line(int _fd)
{
	static char	*buffer;
	char		*line;
	char		*buf;

	if (_fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = new_line(_fd, buf, buffer);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	buffer = extract(line);
	return (line);
}
/*
# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}*/