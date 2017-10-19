#include "filler.h"

t_game	get_player(t_game game)
{
	char	*buf;

	buf = simple_gnl_from_SI();
	if (!buf)
		return (game);
	if (buf[10] == '1')
		game.pl[0] = 'o';
	else
		game.pl[0] = 'x';
	free(buf);
	game.pl[1] = game.pl[0] - 32;
	return (game);
}

t_game	get_map(t_game game)
{
	char	**map;
	char	*buf;
	int		i;
	int		j;

	i = 0;
	buf = simple_gnl_from_SI();
	while (!ft_isdigit(buf[i]))
		i++;
	if (!(map = malloc(sizeof(char*) * ((game.ymap = simatoi(&(buf[i]))) + 1))))
		return (game);
	j = 0;
	while (simatoi(buf) != game.ymap - 1)
	{
		free(buf);
		buf = simple_gnl_from_SI();
		if (buf[0] != ' ')
			map[j++] = ft_strsub(buf, 4, (ft_strlen(buf) - 4));
	}
	game.xmap = ft_strlen(buf) - 4;
	free(buf);
	map[j] = NULL;
	game.map = map;
	return(get_piece(game));
}

t_game	get_piece(t_game game)
{
	char	*buf;
	int		i;
	int		y_piece;

	buf = simple_gnl_from_SI();
	i = 0;
	while (!(ft_isdigit(buf[i])))
		i++;
	y_piece = simatoi(&(buf[i]));
	if (!(game.piece = malloc(sizeof(char*) * (y_piece + 1))))
		return (game); //ERREUR
	free(buf);
	i = 0;
	while (i < y_piece)
		game.piece[i++] = simple_gnl_from_SI();
	game.piece[i] = NULL;
	return (game);
}

int		is_ennemy(char c, t_game game)
{
	if (c == game.pl[0])
		return (0);
	if (c == game.pl[1])
		return (0);
	if (c == '.')
		return (0);
	return (1);
}














