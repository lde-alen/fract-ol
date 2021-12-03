/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:40:06 by lde-alen          #+#    #+#             */
/*   Updated: 2021/10/09 07:36:46 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*str;
	size_t	len_dest;
	size_t	len_src;
	size_t	res;
	size_t	i;

	str = (char *)src;
	len_src = ft_strlen(str);
	len_dest = ft_strlen(dst);
	res = 0;
	i = 0;
	if (dstsize > len_dest)
		res = len_src + len_dest;
	else
		res = len_src + dstsize;
	while (str[i] && (len_dest + 1) < dstsize)
	{
		dst[len_dest] = str[i];
		len_dest++;
		i++;
	}
	dst[len_dest] = '\0';
	return (res);
}
