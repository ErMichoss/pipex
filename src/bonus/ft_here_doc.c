/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:58:40 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/18 16:30:14 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

void	here_doc(char *argv, t_pipex *pipex)
{
	int		file;
	char	*buf;

	file = open(".doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
		ft_error_msg("error con el here_doc", 1);
	while (1)
	{
		write(1, "Here_Doc>", 10);
		if (get_next_line(0, &buf) < 1)
			exit(1);
		if (!ft_strncmp(argv, buf, ft_strlen(argv + 1))
			&& ft_strlen(buf) - 1 == ft_strlen(argv))
			break ;
		write(file, buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	close(file);
	pipex->infile = open(".doc_tmp", O_RDONLY);
	if (pipex->infile < 0)
	{
		unlink(".doc_tmp");
		ft_error_msg("error con el here_doc", 1);
	}
}
