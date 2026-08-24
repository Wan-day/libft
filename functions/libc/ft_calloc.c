#include "libft.h"

void *calloc(size_t n, size_t size)
{
	unsigned char	*result;
	size_t			i;
	size_t			len;

	i = 0;
	if (size != 0 && n > SIZE_MAX / size)
		return (NULL);
	len = n * size;
	result = malloc(len);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
