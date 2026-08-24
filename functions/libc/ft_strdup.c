/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:39:40 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 18:39:41 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inldue "libft.h"

char *strdup(const char *s)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
