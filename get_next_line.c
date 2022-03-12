#include "get_next_line.h"

char	*getline(char **buf)
{
	char	*res;
	char	*t;
	int		i;
	int		mv;

	while (i = read(fd, *buf, BUFFER_SIZE)
	{
		*buf[i] = '\0';
		t = ft_strchr(*buf, '\n');
		if (t == NULL)
		{
			t = ft_strjoin(t, *buf);
		}
		if (t != NULL)
		{
			mv = t - *buf + 1;
			res = ft_substr(buf, 0, mv);
			res = ft_strjoin(t, res);
			buf = t + 1;
			return (res)
		}
	}
	return (t);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*res;
	char		*t;
	int			mv;

	t = ft_strchr(buf, '\n');
	if (t != NULL)
	{
		mv = t - buf + 1;
		res = ft_substr(buf, 0, mv);
		buf = t + 1;
		return (res);
	}
	getline()
}
