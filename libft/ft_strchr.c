/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:26:53 by lde-alen          #+#    #+#             */
/*   Updated: 2021/10/09 05:03:31 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = ft_strlen((char *)s) + 1;
	j = 0;
	while (j < i)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
		j++;
	}
	return (NULL);
}
