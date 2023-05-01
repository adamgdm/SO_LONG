#include "so_long.h"

int ft_ends_with_ber(char* str)
{
    int len;
    int i;

    len = 0;
    i = 1;
    while (str[len])
        len++;
    if (len < 4)
        return 0;
    while (i <= 3) 
    {
        if (str[len-i] != ".ber"[4-i])
            return 0;
        i++;
    }
    if (len == 4)
        return 0;
    return 1;
}

int ft_name_test(char *name, char* av)
{
    int fd;

    if (!ft_ends_with_ber(av))
        return (0);
    fd = open(name, O_RDONLY);
    close (fd);
    if (fd == -1)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    char *name;
    int line_count;
    void *mlx_inst = NULL;

    line_count = 0;
    if (ac == 2)
    {
        name = ft_cat("", av[1]);
        if (!ft_name_test(name ,av[1]))
        {
            printf("Error : Name of the file is wrong!\n");
            return (0);
        }
        if (ft_check_map(name, &line_count))
        {
            mlx_inst = mlx_init();
            ft_bismillah(name, mlx_inst, line_count);
        }
        else
            printf("Invalid Map\n");
        free (name);
    }
    else
        printf("Wrong argument count\n");
}