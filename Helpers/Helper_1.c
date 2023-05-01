#include "../so_long.h"

int ft_strlen_no_nw(char *s)
{
	int	i;
    int j;

	i = 0;
    j = 0;
	if (!s)
		return (0);
    while (s[i])
    {
        if (s[i] == '\n')
		    j++;
        i++;
    }
    return (i-j);
}

char *ft_cat(const char *str1, const char *str2) 
{
    int     len1;
    int     len2;
    char    *result;
    int     i;
    int     j;

    len1 = (int)ft_strlen(str1);
    len2 = (int)ft_strlen(str2);
    result = (char *) malloc((len1 + len2 + 1) * sizeof(char));
    if (!result)
        return (0); 
    i = 0;
    while (i < len1) 
    {
        result[i] = str1[i];
        i++;
    }
    j = 0;
    while (j < len2) 
    {
        result[i + j] = str2[j];
        j++;
    }
    result[i + j] = '\0';
    return (result);
}

int ft_check_for_ones(char *line, int lines, int line_count)
{
    int i;
    int j;
    int return_value;

    i = 0;
    j = ft_strlen_no_nw(line);
    return_value = 0;
    if (line_count == 1 || lines == line_count)
    {
        while (i < j)
        {
            if (line[i] != '1')
                return_value = 1;
            i++;    
        }
    }
    else
    {
        if (line[0] != '1' || line[ft_strlen_no_nw(line) - 1] != '1')
            return_value = 1;
    }
    free (line);
    return (return_value);
}

int ft_check_zocep(char *line, int i, int j)
{
    if (line[i] != 'P' && line[i] != 'C' &&
        line[i] != '0' && line[i] != '1' &&
        line[i] != 'E' && line[i] > ' ')
    {    
        free(line);
        return (0);
    }
    else if (i == j - 1)
        free(line);
    return(1);    
}