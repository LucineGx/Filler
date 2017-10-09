#include "filler.h"

void	puttab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl_fd(tab[i], fd);
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
