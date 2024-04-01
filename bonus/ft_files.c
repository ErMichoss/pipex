/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:39:43 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/01 11:29:48 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

int	check_heredoc(char *argv, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", argv, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	ft_infile(char **argv, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc(argv[2], pipex);
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			ft_error_msg("error con el infile", 1);
	}
}

void	ft_outfile(char *argv, t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		ft_error_msg("error con el outfile", 1);
}
