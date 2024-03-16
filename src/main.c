/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:46:07 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/15 20:21:11 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	*ft_findpath(char **envp)
{
	while (strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	ft_error_msg(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	exit(1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc == 1)
		ft_error_msg("You must put arguments in order for pipex to work");
	else if (argc != 5)
		ft_error_msg("Invalid number of arguments!");
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile == -1)
		ft_error_msg("Error opening file");
	pipex.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile == -1)
		ft_error_msg("Error opening file");
	if (pipe(pipex.pipe_fd) < 0)
		ft_error_msg("Error with pipe");
	pipex.paths = ft_findpath(envp);
	pipex.comands = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_exec_cmd1(argv, envp, pipex);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		ft_exec_cmd2(argv, envp, pipex);
	return (0);
}
