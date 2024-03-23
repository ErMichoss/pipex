/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by nicgonza          #+#    #+#             */
/*   Updated: 2024/03/23 12:04:28 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
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

void	ft_close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->num_pipes))
	{
		close(pipex->pipe_fd[i]);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc < check_heredoc(argv[1], &pipex))
		ft_error_msg("The number of arguments introduced is incorrect", 1);
	ft_infile(argv, &pipex);
	ft_outfile(argv[argc - 1], &pipex);
	pipex.num_cmd = argc - 3 - pipex.here_doc;
	pipex.num_pipes = 2 * (pipex.num_cmd - 1);
	pipex.pipe_fd = (int *)malloc((sizeof (int)) * pipex.num_pipes);
	if (!pipex.pipe_fd)
		ft_error_msg("Error al reservar memoria para los pipes", 1);
	pipex.paths = find_path(envp);
	pipex.comands = ft_split(pipex.paths, ':');
	if (!pipex.comands)
		free_pipe(&pipex);
	create_pipes(&pipex);
	pipex.pipe_id = -1;
	while (++(pipex.pipe_id) < pipex.num_cmd)
	{
		ft_exec_comands(pipex, argv, envp);
		ft_close_pipes(&pipex);
		waitpid(-1, NULL, 0);
	}
	process_free(&pipex);
	return (0);
}
