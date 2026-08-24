/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:54:29 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/19 17:13:58 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memset(void *s, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	value;

	arr = (unsigned char*)b;
	value = c;
	while (n--)
	{
		*arr = value;
		arr++;
	}
	return (s);
}
