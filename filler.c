#include "filler.h"

t_game	init_game(void)
{
	t_game new;

	new.pl[0] = '.';
	new.pl[1] = '.';
	new.xmap = 0;
	new.ymap = 0;
	new.map = NULL;
	new.piece = NULL;
	return (new);
}

char	*simple_gnl_from_SI(void)
{
	char	*buf;
	char	*ret;

	ret = NULL;
	if (!(buf = malloc(sizeof(char) * 2)))
		return (NULL); //ADD PUTERROR
	buf[0] = '\0';
	buf[1] = '\0';
	read(0, buf, 1);
	while (buf && buf[0] != '\n')
	{
		ret = ft_strjoin_free(ret, buf, 1);
		read(0, buf, 1);
	}
	free(buf);
	return (ret);
}

void		play(t_potmove *final_move)
{
	char ret[4];
	ret[0] = final_move->x + 48;
	ret[1] = ' ';
	ret[2] = final_move->y + 48;
	ret[3] = '\n';
	write(1, ret, 4);
}

int			main(void)
{
	t_game		game;
	t_potmove	*lst;
	t_potmove	*tmp;

	game = init_game();
	game = get_player(game);
	while (2)
	{
		game = get_map(game);
		if (your_turn(game))
		{
			lst = get_all_positions(game);
			tmp = move_choice(game, lst, 0, game.xmap + game.ymap);
			play(tmp);
		}
		free_game(game, lst);//
	}
	return (0);
}
