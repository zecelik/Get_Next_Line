#include "get_next_line_bonus.h"

char	*ft_new_left_str(char *remainder)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen() - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while ([i])
		str[j++] = remainder[i++];
	str[j] = '\0';
	free();
	return (str);
}

char	*ft_get_line(char *remainder)
{
	int		i;
	char	*str;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_to_left_str(int fd, char *remainder)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(remainder, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		remainder = ft_strjoin(remainder, buff);
	}
	free(buff);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*remainder[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remainder[fd] = ft_read_to_left_str(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	str = ft_get_line(remainder[fd]);
	remainder[fd] = ft_new_left_str(remainder[fd]);
	return (str);
}
// int	main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	int resfd = open("result.txt", O_RDWR);
//  	char  *line;
// 	for (int i = 0; i < 2; i++) {
// 		if (i%2)
// 			line = get_next_line(fd2);
// 		else
// 			line = get_next_line(fd);
//  		write(resfd, line, ft_strlen(line));
// 	}
// }