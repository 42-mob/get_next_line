#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	size_t	i;
	char	*ptr;

	if (!s1)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	ptr = malloc((s1_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_len;
	char			*copy;

	s_len = ft_strlen(s);
	if (start > s_len || len <= 0)
		return (ft_strdup(""));
	if ((start + len) > s_len)
	{
		copy = (char *) ft_calloc(s_len - start + 1, sizeof(char));
		if (!copy)
			return (NULL);
		ft_strlcpy(copy, s + start, s_len - start + 1);
		return (copy);
	}
	copy = (char *) ft_calloc(len + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s + start, len + 1);
	return (copy);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nbr, size_t size)
{
	char	*p;
	char	*pointer;
	size_t	amount;
	size_t	i;

	amount = nbr * size;
	p = (char *) malloc(amount);
	if (!p)
		return (NULL);
	pointer = p;
	i = 0;
	while (i < amount)
	{
		*p = 0;
		i++;
		p++;
	}
	return ((void *) pointer);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	j;

	src_len = ft_strlen(src);
	j = 0;
	if (size != 0)
	{
		while (j < size - 1 && j != src_len)
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = 0;
	}
	return (src_len);
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
