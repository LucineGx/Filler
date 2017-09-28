#include "filler.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int id;
	int is;

	if (!dest || !src)
		return (dest);
	id = 0;
	is = 0;
	while (dest[id])
		id++;
	while (src[is])
		dest[id++] = src[is++];
	dest[id] = '\0';
	return(dest);
}

char	*ft_strdup(char *s)
{
	char *ret;

	if (!s)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	return (ft_strcpy(ret, s));
}

char	*ft_strjoin_free(char *s1, char *s2, int f)
{
	char *ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
		ret = (s1 == NULL) ? ft_strdup(s2) : ft_strdup(s1);
	else
	{
		if (!(ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ret = ft_strcpy(ret, s1);
		ret = ft_strcat(ret, s2);
	}
	if (s1 && (f == 1 || f == 3))
		free(s1);
	if (s2 && (f == 2 || f == 3))
		free(s2);
	return (ret);
}
