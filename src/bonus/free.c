/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:10:22 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/18 16:29:09 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

void	process_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".doc_tmp");
	while (pipex->comands[i])
	{
		free(pipex->comands[i]);
		i++;
	}
	free(pipex->comands);
	free(pipex->pipe_fd);
}

void	free_pipe(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".doc_tmp");
	free(pipex->pipe_fd);
	exit(1);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->comand[i])
	{
		free(pipex->comand[i]);
		i++;
	}
	free(pipex->comand);
	free(pipex->exe);
}
