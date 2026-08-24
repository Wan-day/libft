void	*memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		to_find;
	const unsigned char	*str;
	
	i = 0;
	to_find = (unsigned char)c;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == to_find)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
