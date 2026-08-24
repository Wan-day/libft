#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;
	size_t	i;

	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	i = 0;
	if (p_src > p_dest)
	{
		while (n--)
		{
		p_dest[i] = p_src[i];
		i++;
		}
	}
	else
	{
		while (n--)
			p_dest[n] = p_src[n];
	}		
	return (dest);
}
