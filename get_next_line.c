#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char		*buffer[BUFF_SIZE + 1];
	char		*tmp_str;
	char		*end_line;
	static char	*fd_tab[FD_MAX];
	int		nbytes;

	if (fd < 0 || fd > FD_MAX || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!fd_tab[fd])
		fd_tab[fd] = ft_strnew(0);
	while (nbytes = read(fd, buffer, BUFF_SIZE) > 0)
	{
		buffer[nbytes] = '\0';
		tmp_str = fd_tab[fd];
		fd_tab[fd] = ft_strjoin(fd_tab[fd], buffer);
		free(tmp_str);
		if (end_line = ft_strchr(buffer, '\n'))
			break ;
	}
	if (nbytes < 0)
		return (-1);
	else if (!nbytes || !fd_tab[fd] || !fd_tab[fd][0])
		return (0);
	if (end_line)
	{
		if (*end_line == fd_tab[fd][0])
			*line = ft_strdup("");
		else
			*line = ft_strndup(fd_tab[fd], end_line - fd_tab[fd]);
		tmp_str = fd_tab[fd];
		fd_tab[fd] = ft_strdup(end_line + 1);
		ft_strdel(&tmp_str);
	}
	else
	{
		*line = ft_strdup(fd_tab[fd]);
		ft_strdel(&fd_tab[fd]);
	}
	if (!(*line))
		return (-1);
	return (1);
}
