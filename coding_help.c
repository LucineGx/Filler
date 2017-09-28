#include "filler.h"

void	puttab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	aff_lst(t_potmove *lst)
{
	while (lst != NULL)
	{
		printf("%d - %d\n", lst->y, lst->x);
		lst = lst->next;
	}
}
