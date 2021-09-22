//#include "get_next_line.h"
//#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd)
{
	char	*buff;
	char	*backup;
	char	*copy;
	int		j;
	int		i;

	j = 0;
	i = 0;
	buff = malloc(BUFF_SIZE * sizeof(char));
	backup = malloc(BUFF_SIZE * sizeof(char));
	read (fd, buff, BUFF_SIZE);
	while (buff[j] != '\n')
		j++;
	copy = ft_substr(buff, 0, j + 1);
	j++;
	while (j < BUFF_SIZE)
	{
		backup[i] = buff[j];
		j++;
		i++;
	}
	printf("backup: %s", backup);
	return (copy);
}

int main(void)
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("string str: %s", str);
	/* str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd); */
	/* while(1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			printf("str vazia\n");
			break ;
		}
		printf("> %s\n", str);
		free(str);
	} */
	return (0);
}
