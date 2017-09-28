#include "filler.h"

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		simatoi(char *s)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (!s)
		return (0);
	while (s[i] && ft_isdigit(s[i]))
	{
		ret = (ret * 10) + s[i] - 48;
		i++;
	}
	return (ret);
}

char	*ft_strsub(char *s, int start, int lengh)
{
	char	*ret;
	int		i;

	i = 0;
	if (!s || !(ret = malloc(sizeof(char) * (lengh + 1))))
		return (NULL);
	while (s[i + start] && lengh != i)
	{
		ret[i] = s[i + start];
		i ++;
	}
	ret[i] = '\0';
	return (ret);
}

int		ft_strncmp(char *s1, char *s2, int lengh)
{
	int i;

	i = 0;
	while (i < lengh && s1 && s2 && s1[i] == s2[i])
		i++;
	if (i == lengh)
		return (0);
	return (s1[i] - s2[i]);
}












