/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:43:18 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/07 11:43:18 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_make_word(char const *str, char c, size_t *index)
{
	char		*word;
	size_t		i;
	size_t		start;

	while (str[*index] == c && str[*index] != '\0')
		(*index)++;
	start = *index;
	while (str[*index] != c && str[*index] != '\0')
		(*index)++;
	word = ft_strnew(*index - start);
	if (!word)
		return (NULL);
	i = 0;
	while (start < *index)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}
