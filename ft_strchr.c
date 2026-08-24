/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:39:37 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 19:04:53 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
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
