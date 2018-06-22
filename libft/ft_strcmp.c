/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:58:40 by mmarcink          #+#    #+#             */
/*   Updated: 2018/02/26 18:58:40 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** An unsigned char can hold any value from 0 to 255
** While loop needs 2 conditions to b true for it to start looping
** and to keep going. This should keep going as long as we havei
** not reached the end of string s1 AND we want the loop to happen only
** while the character at position i in s1 is the same as the character
** postion i in s2. The first difference we find in the 2 strings
** to compare the lexicographical difference (size of ascii num).
*/
#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
