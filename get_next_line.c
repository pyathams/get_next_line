/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:14:50 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/17 02:14:50 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_line_buffer(int fd , char *buf, char *final)
{
	int	read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!final)
			final = ft_strdup("");
		char_temp = final;
		final = ft_strjoin(char_temp,buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (final);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	if (line[count] != '\0')
		return (NULL);
	backup = ft_substr(line, count + 1, ft_strlen(line)- count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
    char		*line;
	char		*buf;
	static char	*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line_buffer(fd, buf, final);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	final = extract(line);
	return (line);
}

int	main(void)
{
	int	fd;
	int i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while(i < 127 && get_next_line(fd))
	{
		printf("%s", get_next_line(fd));
		i++;
	}
}