#include "filler.h"

int			check_one_pos(t_game g, int y, int x)
{
	int xp;
	int yp;
	int check;

	yp = -1;
	check = 0;
	while (g.piece[++yp] && g.map[y] && check >= 0)
	{
		xp = -1;
		while (g.piece[yp][++xp] && g.map[y][x] && check >= 0)
			if (g.map[y][x++] != '.' && g.piece[yp][xp] != '.')
			{
				if (g.map[y][x - 1] != g.pl[0] && g.map[y][x - 1] != g.pl[1])
					check = -2;
				check++;
			}
		if (g.piece[yp][xp] && !g.map[y][x])
			check = -1;
		x -= xp;
		y++;
	}
	if ((g.piece[yp] && !g.map[y]) || check != 1)
		return (0);
	return (1);
}

void		new_pot_move(t_potmove **lst, int y, int x)
{
	t_potmove *new;
	t_potmove *tmp;

	new = malloc(sizeof(t_potmove));
	new->x = x;
	new->y = y;
	new->next = NULL;
	tmp = (*lst);
	if (!tmp)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_potmove	*get_all_positions(t_game game)
{
	t_potmove	*lst;
	int			pos;

	lst = NULL;
	pos = 0;
	while (pos < game.xmap * game.ymap)
	{
		if (check_one_pos(game, pos / game.xmap, pos % game.xmap))
			new_pot_move(&lst, pos / game.xmap, pos % game.xmap);
		pos++;
	}
	return (lst);
}























