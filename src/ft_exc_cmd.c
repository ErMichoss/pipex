/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:26 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/16 16:08:27 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

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

void	ft_exec_cmd1(char **argv, char **envp, t_pipex pipex)
{
	dup2(pipex.pipe_fd[1], 1);
	close(pipex.pipe_fd[0]);
	dup2(pipex.infile, 0);
	pipex.comand = ft_split(argv[2], ' ');
	pipex.exe = get_comand(pipex.comands, pipex.comand[0]);
	if (!pipex.exe)
	{
		free_process(&pipex);
		ft_error_msg("Comando not found :(");
		exit(1);
	}
	execve(pipex.exe, pipex.comand, envp);
}

void	ft_exec_cmd2(char **argv, char **envp, t_pipex pipex)
{
	dup2(pipex.pipe_fd[0], 0);
	close(pipex.pipe_fd[1]);
	dup2(pipex.outfile, 1);
	pipex.comand = ft_split(argv[3], ' ');
	pipex.exe = get_comand(pipex.comands, pipex.comand[0]);
	if (!pipex.exe)
	{
		free_process(&pipex);
		ft_error_msg("Comando not found :(");
		exit(1);
	}
	execve(pipex.exe, pipex.comand, envp);
}
