#include "../so_long.h"

int ft_cloc_x(char **map, char c) {
    int i = 0, j = 0;
    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            if (map[i][j] == c) {
                return j;
            }
            j++;
        }
        i++;
        j = 0;
    }
    return -1; // return -1 if the character is not found
}

int ft_cloc_y(char **map, char c) {
    int i = 0, j = 0;
    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            if (map[i][j] == c) {
                return i;
            }
            j++;
        }
        i++;
        j = 0;
    }
    return -1; // return -1 if the character is not found
}

int ft_check_last_line(char **map) 
{
    int last_row = 0;

    while (map[last_row] && map[last_row][0] != '\0')
        last_row++;

    if (last_row == 0)
        return 1; // empty map

    if (map[last_row - 1][ft_strlen(map[last_row - 1]) - 1] == '\n')
        return 1;
    return 0;
}