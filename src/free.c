/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:37:40 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/23 11:25:20 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	free_program(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->comands[i])
	{
		free(pipex->comands[i]);
		i++;
	}
	free(pipex->comands);
}

void	free_process(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->comands[i])
	{
		free(pipex->comands[i]);
		i++;
	}
	free(pipex->comands);
	free(pipex->exe);
	ft_error_msg("Command not found\n", 1);
}
