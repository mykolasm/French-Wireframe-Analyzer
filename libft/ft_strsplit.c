/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:11:32 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/06 17:11:32 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**str_split;

	i = 0;
	words = 0;
	if (!s || !c)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	if (!(str_split = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
		str_split[i++] = ft_make_word(s, c, &j);
	str_split[i] = 0;
	return (str_split);
}
