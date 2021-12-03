/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:05:12 by lde-alen          #+#    #+#             */
/*   Updated: 2021/11/02 09:15:20 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fputstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_fputchar(str[i]);
		i++;
	}
	exit(EXIT_FAILURE);
}
