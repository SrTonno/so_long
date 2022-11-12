
#include "get_next_line_bonus.h"

static int	count_deli(char const *s, char c, int i)
{
	int	word;
	int	count;

	word = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			word = 0;
		}
		i++;
	}
	return (count);
}

static int	skip(char const *s, int i, char c, int type)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0' && type != 2)
		i++;
	if (s[i] == '\0')
		return (i);
	while (s[i] == c && type == 0)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		first;
	int		j;
	int		end;
	char	*pnt;
	char	**index;

	if (!s)
		return (NULL);
	j = 0;
	first = skip(s, 0, c, 2);
	index = ft_calloc((count_deli(s, c, 0) + 1), sizeof(char *));
	if (!index)
		return (NULL);
	while (s[first] != '\0')
	{
		end = skip(s, first, c, 1);
		pnt = ft_substr(s, first, end - first);
		if (!pnt)
			return (NULL);
		first = skip(s, first, c, 0);
		index[j++] = pnt;
	}
	return (index);
}
