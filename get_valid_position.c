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
	printf("game.xmap = %d | game.ymap = %d\n", game.xmap, game.ymap);
	while (pos < game.xmap * game.ymap)
	{
		if (check_one_pos(game, pos / game.xmap, pos % game.xmap))
			new_pot_move(&lst, pos / game.xmap, pos % game.xmap);
		pos++;
	}
	return (lst);
}

int			dist(int ya, int xa, int yb, int xb)
{
	int ret;

	ret = (xa - xb >= 0) ? xa - xb : xb - xa;
	ret += (ya - yb >= 0) ? ya - yb : yb - ya;
	return (ret);
}

t_potmove	*move_choice(t_game g, t_potmove *lst, int i, int smallest)
{
	t_potmove *tmp;
	t_potmove *ret;

	ret = NULL;
	while (i < g.xmap * g.ymap && !is_ennemy(g.map[i / g.xmap][i % g.xmap], g))
		i++;
	if (i >= g.xmap * g.ymap)
		return (NULL);
	tmp = lst;
	while (tmp != NULL)
	{
		if (dist(i / g.xmap, i % g.xmap, tmp->y, tmp->x) < smallest)
		{
			smallest = dist(i / g.xmap, i % g.xmap, tmp->y, tmp->x);
			ret = tmp;
		}
		tmp = tmp->next;
	}
	tmp = move_choice(g, lst, i + 1, smallest);
	if (tmp)
		return (tmp);
	return (ret);
}























