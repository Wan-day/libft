#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	*p_delim;
	char	**result;
	size_t	len_s;

	len_s = ft_strlen(s);
	p_delim = ft_strchr(s, c);
	if (p_delim = NULL)
	{
		result = malloc(sizeof(int) * 2);
		if (result == NULL)
			return (NULL);
		result[0] = strdup(s);
		if (result[0] == NULL)
			return (NULL);
		result[1] = NULL;
		return (result);
	}
	else
	{
		result = malloc(sizeof(int) * 3);
		if (result == NULL)
			return (NULL);
		result[1] = ft_substr(s, (p_delim + 1), len_s);
		result[2] = NULL;
		result[0] = malloc(p_delim - s + (1 * sizeof(char)));
		if (result[0] == NULL || result[1] == NULL)
			return (NULL);
		(void)ft_strlcpy(result[0], s, (p_delim - s));
		return (result);
	}
}
