#include "so_long.h"
/*
int ft_check_char_count(char *str, int current_cc, int char_count, int line_count)
{
    int fd;
    char *line;
    
    fd = open(str, O_RDONLY, 777);
    if (fd == -1)
    {
        printf("wow");
        exit (0);
    }
    line = get_next_line(fd);
    if (!line)
        return (0);
    line_count++;
    char_count = ft_strlen_no_nw(line);
    while (line)
    {
        current_cc = ft_strlen_no_nw(line);
        free(line);
        if (char_count != current_cc || !line[0]|| char_count < 4)
        {
            close (fd);
            return (0);
        }
        line = get_next_line(fd);
        if (!line)
        {
            close (fd);
            return (line_count);
        }
        line_count++;
    }
    return (line_count);
}*/
int ft_check_char_count(char *str, int char_count, int line_count)
{
    int fd;
    char buffer[1];
    
    fd = open(str, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char_count = 0;
    line_count = 0;
    int is_line_valid = 1;
    int is_file_empty = 1;
    while (read(fd, buffer, 1)) {
        is_file_empty = 0;
        if (buffer[0] == '\n') {
            if (is_line_valid && char_count >= 4) {
                line_count++;
            }
            char_count = 0;
            is_line_valid = 1;
        } else if (buffer[0] != ' ' && buffer[0] != '\t') {
            char_count++;
            if (char_count > 80) {
                is_line_valid = 0;
            }
        }
    }
    if (is_line_valid && char_count >= 4) {
        line_count++;
    }
    close(fd);
    if (is_file_empty) {
        return 0;
    }
    return line_count;
}

int ft_check_edges(char *name, int lines, int line_count)
{
    int fd;
    char *line;
    
    fd = open(name, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
        return (0);
    line_count++;
    while (line)
    {
        if (ft_check_for_ones(line, lines, line_count))
        {
            close (fd);  
            return(0);
        }
        line = get_next_line(fd);
        if (!line)
        {
            close (fd);
            return (1);
        }
        line_count++;
    }
    return (1);
}

int ft_check_characters(char *name)
{
    int i;
    int fd;
    char *line;
    int j;

    fd = open(name, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
        return (0);
    while (line)
    {
        i = 0;
        j = ft_strlen(line);
        while (i < j)
        {
            if (!ft_check_zocep(line, i, j))
            {
                close (fd);
                return (0);
            }
            i++;
        }
        line = get_next_line(fd);
    }
    return (1);
}

int ft_check_map(char *name, int *line_count)
{
    char **map;
    int e_presence;

    e_presence = 0;
    *line_count = ft_check_char_count(name,0,0);
    if (*line_count < 3)
        return (0);
    if (!ft_check_edges(name, *line_count, 0))
        return (0);
    if (!ft_check_characters(name))
        return (0); 
    map = ft_fill_map(name, *line_count);
    if (!ft_check_p_and_e(map) || ft_check_last_line(map))
        return (ft_free(map, *line_count, -1));
    ft_fill_the_shit(map, ft_cloc_x(map,'P'), ft_cloc_y(map,'P'), &e_presence);
    if (ft_check_c(map, 'C') || !e_presence || ft_check_c(map, 'P'))
        return (ft_free(map, *line_count, -1));
    ft_free(map, *line_count, -1);
    return (1);
}