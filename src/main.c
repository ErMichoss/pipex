/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:46:07 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/31 11:12:44 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	*ft_findpath(char **envp)
{
	while (strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	ft_error_msg(char *s, int n)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	if (n == 1)
		exit(1);
}

static void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error_msg("Invalid number of arguments!", 1);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile == -1)
		ft_error_msg("Error opening file", 1);
	pipex.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile == -1)
		ft_error_msg("Error opening file", 1);
	if (pipe(pipex.pipe_fd) < 0)
		ft_error_msg("Error with pipe", 1);
	pipex.paths = ft_findpath(envp);
	pipex.comands = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_exec_cmd1(argv, envp, pipex);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		ft_exec_cmd2(argv, envp, pipex);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_program(&pipex);
	return (0);
}
