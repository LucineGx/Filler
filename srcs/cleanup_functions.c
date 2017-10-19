#include "filler.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_lst(t_potmove *lst)
{
	if (lst->next != NULL)
		free_lst(lst->next);
	free(lst);
	lst = NULL;
}

void	free_game(t_game game, t_potmove *lst)
{
	free_tab(game.map);
	free_tab(game.piece);
	if (lst)
		free_lst(lst);
}
