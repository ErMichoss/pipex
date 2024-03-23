/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:53:14 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/02 17:43:33 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

int	ft_strncmp(char *str, char *dst, int numb)
{
	int	i;

	i = 0;
	while ((str[i] != '\0' || dst[i] != '\0') && i < numb)
	{
		if (str[i] != dst[i])
			return ((char)str[i] - (char)dst[i]);
		i++;
	}
	return (0);
}
