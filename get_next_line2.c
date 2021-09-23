#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include "get_next_line.h"

char	*join_line(int fd, char *line, char	*buffer, char *backup)
{
	char	*line;
	char	*temp;
	int		i;
	
	if (!ft_strchr(buffer, '\n'))
	{
		line = ft_strjoin(line, buffer);
	}
	else
	{
		i = 0;
		while (buffer[i] != '\n')
			i++;
		temp = ft_substr(buffer, 0, i + 1);
		line = ft_strjoin(line, temp);
		backup = ft_strdup(&buffer[i + 1]);
		free(temp);
		free(buffer);
	}
	return (line);
}

char	*read_line(int fd, char *backup, char *buffer)
{
	char	*line;
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	line = ft_strdup("");
	while (bytes_read > 0 /*buffer != '\n'*/)
	{
		line = join_line(fd, line, buffer, backup);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buffer;
	char		*line;
	char		*temp;
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(backup, '\n'))
	{
		j = 0;
		while (backup[j] != '\n')
			j++;
		line = ft_substr(backup, 0, j);
		free (backup);
		return (line);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	
	line = read_line(fd, backup, buffer);

	
	i = 0;
	
}

int	main(void)
{
	int 	fd;
	char	*check;
	
	fd = open("teste", O_RDONLY);
	check = get_next_line(fd);
	printf(">:|%s|\n", check);
	return (0);
}
