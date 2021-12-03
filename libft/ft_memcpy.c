/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:25:15 by lde-alen          #+#    #+#             */
/*   Updated: 2021/10/09 04:59:12 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	const char		*tmp_src;
	char			*tmp_dest;

	tmp_src = src;
	tmp_dest = dst;
	i = 1;
	if (!(tmp_dest || tmp_src))
		return (NULL);
	while (i <= n)
	{
		*tmp_dest = *tmp_src;
		tmp_dest++;
		tmp_src++;
		i++;
	}
	return (dst);
}
