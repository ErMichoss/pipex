/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:00:06 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/16 16:05:20 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

char	*get_comand(char **paths, char *comand)
{
	char	*tmp;
	char	*exe;

	if ((comand[0] >= 'a' && comand[0] <= 'z')
		|| (comand[0] >= 'A' && comand[0] <= 'Z')
		|| (comand[0] >= '0' && comand[0] <= '9'))
	{
		while (*paths)
		{
			tmp = ft_strjoin(*paths, "/");
			exe = ft_strjoin(tmp, comand);
			free(tmp);
			if (access(exe, 0) == 0)
				return (exe);
			free(exe);
			paths++;
		}
	}
	return (NULL);
}

void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->num_cmd - 1)
	{
		if (pipe(pipex->pipe_fd + 2 * i) < 0)
			process_free(pipex);
		i++;
	}
}

static void	ft_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	ft_exec_comands(t_pipex pipex, char **argv, char **envp)
{
	pipex.pid = fork();
	if (!pipex.pid)
	{
		if (pipex.pipe_id == 0)
			ft_dup2(pipex.infile, pipex.pipe_fd[1]);
		else if (pipex.pipe_id == pipex.num_cmd - 1)
			ft_dup2(pipex.pipe_fd[2 * pipex.pipe_id - 2], pipex.outfile);
		else
			ft_dup2(pipex.pipe_fd[2 * pipex.pipe_id - 2],
				pipex.pipe_fd[2 * pipex.pipe_id + 1]);
		ft_close_pipes(&pipex);
		pipex.comand = ft_split(argv[2 + pipex.here_doc + pipex.pipe_id], ' ');
		pipex.exe = get_comand(pipex.comands, pipex.comand[0]);
		if (!pipex.exe)
		{
			ft_error_msg("error al ejecutar e comando");
			child_free(&pipex);
			exit(1);
		}
		execve(pipex.exe, pipex.comand, envp);
	}
}
