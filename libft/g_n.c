/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_n.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:22 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:22 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	g_n(char const *s, char c)
{
	int num_of_words;
	int i;
	int in_word;

	i = 0;
	num_of_words = 0;
	in_word = 0;
	while (s[i])
	{
		if (!in_word && s[i] != c)
		{
			num_of_words++;
			in_word = 1;
		}
		else if (in_word && s[i] == c)
			in_word = 0;
		i++;
	}
	return (num_of_words + 1);
}
