/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:37:40 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/08 12:45:15 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	free_process(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->comand[i])
	{
		free(pipex->comands[i]);
		i++;
	}
	free(pipex->comands);
	free(pipex->exe);
}
