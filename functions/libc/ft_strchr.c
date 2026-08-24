char *strchr(const char *s, int c)
{
	unsigned char		test;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	test = (unsigned char)c;
	while (*str)
	{
		if (*str == test)
			return (s);
		str++;
		s++;
	}
	if (*str == test)
		return (s);
	else
		return (NULL);
}
