/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:26 by nicgonza          #+#    #+#             */
/*   Updated: 2024/02/22 15:17:09 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_comand(char **paths, char *comand)
{
	char	*tmp;
	char	*exe;

	while (*paths)
	{
		tmp = strjoin(*paths, "/");
		exe = strjoin(tmp, comand);
		free(tmp);
		if (access(exe, 0) == 0)
			return (exe);
		free(exe);
		paths++;
	}
	return (NULL);
}

void	ft_exec_cmd1(char **argv, char **envp, t_pipex *pipex)
{
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.infile, 0);
	pipex.comand = ft_split(argv[2], ' ');
	pipex.exe = get_comand(pipex.comands, pipex.comand[0]);
	if (!pipex.exe)
	{
		//termina el proceso y manda msg de error.
	}
}
