#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 11
# define FD_MAX 65535

int	get_next_line(const int fd, char **line);

#endif
