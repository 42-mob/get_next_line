#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include "get_next_line.h"

void	free_null(char **ptr)
{
	if(*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}
// void	free_null(char *ptr)
// {
// 	free(ptr);
// 	ptr = NULL;
// }

char	*join_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	res = NULL;
	if(nl_position <= 0)
	{
		if (**buffer == '\0')
		{
			free_null(buffer);
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	res = *buffer;
	res[nl_position] = 0;
	*buffer = tmp;
	return(res);

	// char	*join_line(char *line, char	*buffer, char **backup)
	// {
	// 	char	*temp;
	// 	int		i;

	// 	if (!ft_strchr(buffer, '\n'))
	// 	{
	// 		if (**backup)//**backup
	// 		{
	// 			line = ft_strjoin(line, *backup);
	// 			free(*backup);
	// 		}
	// 		line = ft_strjoin(line, buffer);
	// 	}
	// 	else
	// 	{
	// 		i = 0;
	// 		while (buffer[i] != '\n')
	// 			i++;
	// 		temp = ft_substr(buffer, 0, i + 1);
	// 		free(*backup);
	// 		// if (**backup)//**backup - verificar a necessidade deste if
	// 		// {
	// 		// 	line = ft_strjoin(line, *backup);
	// 		// 	//free(backup);
	// 		// }
	// 		line = ft_strjoin(line, temp);
	// 		*backup = ft_strdup(&buffer[i + 1]); //fazer um check if buffer	[buff_size - 1] = \n
	// 		//free(temp);
	// 		//free(buffer);
	// 	}
	// 	return (line);
	// }
}

char	*read_line(int fd, char **buffer, char *read_return)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*nl;


	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			return(join_line(bytes_read, buffer));
		}
		read_return[bytes_read] = 0;
		tmp = ft_strjoin(*buffer, read_return);
		free_null(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return(join_line(nl - *buffer + 1, buffer));

// char	*read_line(int fd, char **backup, char *buffer)
// {
// 	char	*line;
// 	int		bytes_read;
// 	char	*n_check;//checar

// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	if (bytes_read <= 0)
// 		return (NULL);
// 	n_check = ft_strchr(buffer, '\n');
// 	line = ft_strdup("");
// 	while (bytes_read > 0 && !n_check)
// 	{
// 		line = join_line(line, buffer, backup);
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		n_check = ft_strchr(buffer, '\n');
// 	}
// 	if (n_check)
// 	{
// 		line = join_line(line, buffer, backup);
// 	}
// 	return (line);
// }
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD + 1];
	char		*read_return;
	char		*res;
	// int			count;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	read_return = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(read_return == NULL)
		return(NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup(""); //da segfault
	// else if (ft_strchr(buffer[fd], '\n'))
	// {
	// 	count = 0;
	// 	while (buffer[fd][count] != '\n')
	// 		count++;
	// 	res = ft_substr(buffer[fd], 0, count);
	// 	free(*buffer);
	// 	return (res);
	// }
	res = read_line(fd, &buffer[fd], read_return);
	free_null(&read_return);
	return (res);

// 	char	*get_next_line(int fd)
// {
// 	static char	*backup[OPEN_MAX];
// 	char		*buffer;
// 	char		*line;
// 	int			count;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!backup[fd])
// 		backup[fd] = ft_strdup(""); //da segfault
// 	if (ft_strchr(backup[fd], '\n'))
// 	{
// 		count = 0;
// 		while (backup[fd][count] != '\n')
// 			count++;
// 		line = ft_substr(backup[fd], 0, count);
// 		free(*backup);
// 		return (line);
// 	}
// 	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));//fazer check
// 	line = read_line(fd, &backup[fd], buffer);
// 	return (line);
// }
}
