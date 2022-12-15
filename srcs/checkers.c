#include "../headers/so_long.h"

int check_ber(char *str)
{
    char *c;

    c = ft_strrchr(str, '.');
    if(!c)
        return (1);
    if(ft_strncmp(c, ".ber", 5))
        return (1);
    return (0);
}

int	check_map_closed(int i)
{
    map()->map_width = length(map()->map);
    map()->map_height = height(map()->map);
	while (i < map()->map_width)
	{
		if (map()->map[0][i] != '1' || map()->map[map()->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < map()->map_height - 1)
	{
		if (map()->map[i][0] != '1' || map()->map[i][map()->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
int check_map_chars(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->map_height)
    {
        j = 0;
        while (j < map->map_width)
        {
            if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'C' && map->map[i][j] != 'E' && map->map[i][j] != 'P')
                return (1);
            map->player += (map->map[i][j] == '1');
            map->exit += (map->map[i][j] == 'E');
            map->collectibles += (map->map[i][j] == 'C');
            j++;
        }
        i++;
    }
    if (map->player != 1 || map->exit != 1 || map->collectibles == 0)
        return (1);
    return (0);
}

