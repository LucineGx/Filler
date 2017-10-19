/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ghosts_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 20:11:05 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/19 20:27:13 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_empty_lines(char **piece)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i >= 0 && piece[i])
	{
		j = 0;
		while (piece[i][j] && piece[i][j] == '.')
			j++;
		if (!piece[i][j])
		{
			i++;
			count++;
		}
		else
			i = -1;
	}
	return (count);
}

int		count_empty_columns(char **piece)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	count = 0;
	while (j >= 0 && piece[0][j])
	{
		i = 0;
		while (piece[i] && piece[i][j] == '.')
			i++;
		if (!piece[i])
		{
			j++;
			count++;
		}
		else
			j = -1;
	}
	return (count);
}

t_game	*manage_ghost_lines(t_game *game)
{
}
