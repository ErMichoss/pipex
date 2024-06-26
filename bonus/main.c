/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/05 18:40:39 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

char	*ft_findpath(char **envp)
{
	if (*envp == NULL)
		ft_error_msg("Error finding PATH variable", 1);
	while (envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return (*envp + 5);
		envp++;
	}
	ft_error_msg("Error finding PATH variable", 1);
	return (NULL);
}

void	ft_error_msg(char *s, int n)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(n);
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

static void	ft_waitpid(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->num_pipes))
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc == 1)
		ft_error_msg("The number of arguments introduced is incorrect", 1);
	if (argc < check_heredoc(argv[1], &pipex))
		ft_error_msg("The number of arguments introduced is incorrect", 1);
	ft_infile(argv, &pipex);
	ft_outfile(argv[argc - 1], &pipex);
	pipex.num_cmd = argc - 3 - pipex.here_doc;
	pipex.num_pipes = 2 * (pipex.num_cmd - 1);
	pipex.pipe_fd = (int *)malloc((sizeof (int)) * pipex.num_pipes);
	if (!pipex.pipe_fd)
		ft_error_msg("Error al reservar memoria para los pipes", 1);
	pipex.paths = ft_findpath(envp);
	pipex.comands = ft_split(pipex.paths, ':');
	if (!pipex.comands)
		free_pipe(&pipex);
	create_pipes(&pipex);
	pipex.pipe_id = -1;
	while (++(pipex.pipe_id) < pipex.num_cmd)
		ft_exec_comands(pipex, argv, envp);
	ft_close_pipes(&pipex);
	ft_waitpid(&pipex);
	process_free(&pipex);
	return (0);
}
