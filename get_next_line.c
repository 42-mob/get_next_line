#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include "get_next_line.h"

char	*join_line(char *line, char	*buffer, char **backup)
{
	char	*temp;
	int		i;

	if (!ft_strchr(buffer, '\n'))
	{
		if (*backup)//**backup
			line = ft_strjoin(line, *backup);
		line = ft_strjoin(line, buffer);
	}
	else
	{
		i = 0;
		while (buffer[i] != '\n')
			i++;
		temp = ft_substr(buffer, 0, i + 1);
		free (*backup);
		if (*backup)//**backup - verificar a necessidade deste if
		{
			line = ft_strjoin(line, *backup);
			//free(backup);
		}
		line = ft_strjoin(line, temp);
		*backup = ft_strdup(&buffer[i + 1]); //fazer um check if buffer[buff_size - 1] = \n
		//free(temp);
		//free(buffer);
	}
	return (line);
}

char	*read_line(int fd, char **backup, char *buffer)
{
	char	*line;
	int		bytes_read;
	char	*n_check;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	n_check = ft_strchr(buffer, '\n');
	line = ft_strdup("");
	while (bytes_read > 0 && !n_check)
	{
		line = join_line(line, buffer, backup);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		n_check = ft_strchr(buffer, '\n');
	}
	if (n_check)
	{
		line = join_line(line, buffer, backup);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buffer;
	char		*line;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	if (ft_strchr(backup[fd], '\n'))
	{
		count = 0;
		while (backup[fd][count] != '\n')
			count++;
		line = ft_substr(backup[fd], 0, count);
		free (*backup);
		return (line);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));//fazer check
	line = read_line(fd, &backup[fd], buffer);
	return (line);
}

// int	main(void)
// {
// 	int 	fd;
// 	char	*check;
// 	fd = open("multiple_line_no_nl", O_RDONLY);
// 	for (int i = 0; i < 3; i++)
// 	{
// 		check = get_next_line(fd);
// 		printf(">:|%s", check);
// 	}
// 	return (0);
// }
