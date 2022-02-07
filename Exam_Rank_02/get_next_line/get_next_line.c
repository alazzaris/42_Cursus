#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd)
{
	int		read_result;
	int		i = 0;
	char	c;
	char	*buffer = malloc(9999);
	
	while((read_result = read(fd, &c, 1) > 0))
	{
		buffer[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if ((!buffer[i - 1] && !read_result) || read_result == -1)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	buffer[i] = '\0';
	return (buffer);
}