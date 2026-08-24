#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;
	size_t	len_big;

	i = 0;
	len_little = ft_strlen(little);
	len_big = ft_strlen(big);
	if (*little == '\0')
		return (big);
	if (len_little > len_big)
		return (NULL);
	while (i + len_little <= len && i + len_little <= len_big)
	{
		if (ft_strncmp(&big[i], little, len_little) == 0)
			return (&big[i]);
		i++;
	}
	return (NULL);
}
