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
		return (NULL);
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

int		play(t_potmove *final_move)
{
	char	*ret;

	if (!final_move)
	{
		write(1, "0 0\n", 9);
		return (1);
	}
	else
	{
		ret = ft_itoa(final_move->y);
		ret = ft_strjoin_free(ret, " ", 0);
		ret = ft_strjoin_free(ret, ft_itoa(final_move->x), 2);
		ret = ft_strjoin_free(ret, "\n", 0);
		write(1, ret, ft_strlen(ret));
		free (ret);
		return (0);
	}
}

int		main(void)
{
	t_game		game;
	t_potmove	*lst;
	t_potmove	*tmp;
	int			end;

	end = 0;
	game = init_game();
	game = get_player(game);
	while (!end)
	{
		game = get_map(game);
		lst = get_all_positions(game);
		tmp = move_choice(game, lst, 0, game.xmap + game.ymap);
		end = play(tmp);
		free_game(game, lst);//
	}
	return (0);
}
