#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dst)
		return (0);
	i = 0;
	while (n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		size;

	size = ft_strlen(s);
	cpy = (char *)malloc(((size + 1) * sizeof(char)));
	if (!cpy)
		return (NULL);
	cpy = ft_memcpy(cpy, s, size + 1);
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*new;

	if (s1 && s2)
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		new = (char *)malloc((l1 + l2 + 1) * sizeof(char));
		if (!new)
			return (NULL);
		ft_memcpy(new, s1, l1);
		ft_memcpy(&new[l1], s2, l2);
		new[l1 + l2] = '\0';
		return (new);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	line = ft_strdup("");
	while (bytes_read != 0 && *buffer != '\n')
	{
		printf("|%s|\n", buffer);
		if (!ft_strchr(buffer, '\n'))
		{
			line = ft_strjoin(line, buffer);
			printf("Teste l |%s|\n", line);
			printf("Teste b |%s|\n", buffer);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
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
