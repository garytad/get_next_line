#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	char	*ptr;
	size_t	i;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	else if (slen < (start + len))
		len = slen - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

char	*line_out(char **str)
{
	char	*t;
	char	*line;
	int		count;

	if (!*str)
		return (NULL);
	if (!ft_strchr(*str, '\n'))
	{
		line = ft_strdup(*str);
		free (*str);
		*str = NULL;
		return (line);
	}
	t = *str;
	*str = ft_strchr(*str, '\n');
	count = *str - t + 1;
	line = ft_substr(t, 0, count);
	*str = *str + 1;
	*str = ft_strdup(*str);
	free(t);
	return (line);
}

char	*get_line(int fd, int size, char *buf)

{
	static char	*temp;
	char		*t;
	int			readres;

	while (1)
	{
		readres = read(fd, buf, size);
		if (readres > 0)
		{
			buf[readres] = '\0';
			if (!temp)
				temp = ft_strdup(buf);
			else
			{
				t = temp;
				temp = ft_strjoin(temp, buf);
				free(t);
			}
		}
		if (readres <= 0 || ft_strchr(temp, '\n'))
			break ;
	}
	return (line_out(&temp));
}

char	*get_next_line(int fd)
{
	int		size;
	char	*line;
	char	*buf;

	size = BUFFER_SIZE;
	buf = (char *)malloc(size + 1);
	if (fd < 0 || size < 1)
	{
		free (buf);
		return (NULL);
	}
	line = get_line(fd, size, buf);
	free (buf);
	return (line);
}
