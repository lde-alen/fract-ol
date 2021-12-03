/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 00:08:03 by lde-alen          #+#    #+#             */
/*   Updated: 2021/10/09 04:59:35 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*tmp_src;
	char			*tmp_src_last;
	char			*tmp_dest;
	char			*tmp_dest_last;

	tmp_src = src;
	tmp_dest = dst;
	tmp_src_last = (char *)(tmp_src + (len - 1));
	tmp_dest_last = (char *)(tmp_dest + (len - 1));
	if (!(tmp_dest || tmp_src))
		return (NULL);
	else if (tmp_dest < tmp_src)
		while (len--)
			*tmp_dest++ = *tmp_src++;
	else
		while (len--)
			*tmp_dest_last-- = *tmp_src_last--;
	return (dst);
}
