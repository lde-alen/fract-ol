/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:08:34 by lde-alen          #+#    #+#             */
/*   Updated: 2021/10/09 05:04:30 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;
	char	*tmp;

	i = 0;
	len = ft_strlen((char *)s1);
	tmp = malloc((sizeof(char) * (len + 1)));
	str = (char *)s1;
	if (tmp == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	while (str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
