/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:05:22 by nicgonza          #+#    #+#             */
/*   Updated: 2024/02/23 10:23:49 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef struct s_pipex{
	pid_t	pid1;
	pid_t	pid2;
	char	*exe;
	char	**comand;
	char	*paths;
	char	**comands;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
}			t_pipex;


//** INIT **

int	main(int argc, char *argv[], char *envp[]);

//** ERRORS **

void	ft_error_msg(char *s);

//** PIPEX **

char	*get_comand(char **paths, char *comand);
void	ft_exec_cmd1(char **argv, char **envp, t_pipex *pipex);
void	ft_exec_cmd2(char **argv, char **envp, t_pipex *pipex);
char	*ft_findpath(char **envp);
void	free_pprocess(t_pipex *pipex);
void	free_process(t_pipex *pipex);

//** SPLIT **

char	**ft_empty_split(void);
char	*ft_strdp_custom(const char *s, size_t n);
char	**ft_free_str(char **aux);
int		ft_countc(char const *s, char c);
char	**ft_split(char const *s, char c);

//** FUNCTIONS **

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *str);

#endif
