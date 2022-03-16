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

	t = *str;
	*str = ft_strchr(t, '\n');
	if (*str == NULL)
	{
		line = ft_strdup(t);
	}
	else
	{
		count = *str - t + 1;
		line = ft_substr(t, 0, count);
		*str = *str + 1;
		*str = ft_strdup(*str);
	}
	if (**str == '\0')
	{
		free (*str);
		str = NULL;
	}
	free (t);
	return (line);
}

char	*get_line(int fd, int size)

{
	static char	*temp;
	char		*buf;
	char		*t;
	int			readres;

	buf = (char *)malloc(size + 1);
	while (!(ft_strchr(temp, '\n')) || readres > 0)
	{
		readres = read(fd, buf, size);
		if (readres > 0)
		{
			buf[readres] = '\0';
			t = temp;
			temp = ft_strjoin(t, buf);
			free (t);
		}
		if (readres < 0 || (temp == NULL && readres == 0))
		{
			free(buf);
			return (NULL);
		}
	}
	free (buf);
	return (line_out(&temp));
}

char	*get_next_line(int fd)
{
	int		size;
	char	*line;

	size = BUFFER_SIZE;
	if (fd < 0 || size < 1)
		return (NULL);
	line = get_line(fd, size);
	return (line);
}
