#ifndef FILLER_H
# define FILLER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>//
# include <stdio.h>//

int fd;

typedef struct	s_potmove
{
	int					x;
	int					y;
	struct s_potmove	*next;
}				t_potmove;

typedef struct	s_game
{
	char	pl[2];
	int		xmap;
	int		ymap;
	char	**map;
	char	**piece;
	int		line_sup;
	int		column_sup;
}				t_game;

char		*simple_gnl_from_SI();
t_game		get_player(t_game game);
t_game		get_map(t_game game);
t_game		get_piece(t_game game);
int			your_turn(t_game game);
t_potmove	*get_all_positions(t_game game);
void		free_game(t_game game, t_potmove *lst);
int			is_ennemy(char c, t_game game);
t_potmove	*move_choice(t_game g, t_potmove *lst, int i, int smallest);
//LIB PART
int			ft_strlen(char *s);
char		*ft_strjoin_free(char *s1, char *s2, int f);
char		*ft_strdup(char *s);
char		*ft_strcpy(char *s1, char *s2);
char		*ft_strcat(char *s1, char *s2);
int			ft_isdigit(char c);
int			simatoi(char *s);
char		*ft_strsub(char *s, int start, int lengh);
int			ft_strncmp(char *s1, char *s2, int lengh);
char		*ft_itoa(int n);
//TO-DELETE PART
void		puttab(char **tab);
void		aff_lst(t_potmove *lst);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putchar_fd(char c, int fd);

#endif
