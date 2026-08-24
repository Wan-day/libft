char *strrchr(const char *s, int c)
{
	unsigned char		test;
	const unsigned char	*str;
	size_t				len;

	len = ft_strlen(s);
	str = (const unsigned char *)s;
	test = (unsigned char)c;
	if (str[len] == test)
		return (&s[len]);
	if (len != 0)
		len--;
	while (len > 0)
	{
		if (str[len] == test)
			return (&s[len]);
		len--;
	}
	if (str[len] == test)
		return (&s[len]);
	return (NULL);
}
