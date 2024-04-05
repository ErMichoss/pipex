/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:47:46 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/04 19:34:31 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <string.h>
# include <stdio.h>

typedef struct s_pipex
{
	char	**comands;
	char	**comand;
	char	*paths;
	char	*exe;
	pid_t	pid;
	int		num_cmd;
	int		num_pipes;
	int		here_doc;
	int		*pipe_fd;
	int		infile;
	int		outfile;
	int		pipe_id;	
}		t_pipex;

//** INIT **

int		main(int argc, char *argv[], char *envp[]);

//** ERRORS **

void	ft_error_msg(char *s, int n);

//** GNL **
int		get_next_line(int fd, char **line);
char	*ft_strchr(char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t b);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);

//** SPLIT **

char	**ft_empty_split(void);
char	*ft_strdup_custom(const char *s, size_t n);
char	**ft_free_str(char **aux);
int		ft_countc(const char *s, char c);
char	**ft_split(char const *s, char c);

//** PIPEX **

void	ft_close_pipes(t_pipex *pipex);
char	*ft_findpath(char **envp);
void	process_free(t_pipex *pipex);
void	free_pipe(t_pipex *pipex);
void	child_free(t_pipex *pipex);
char	*get_comand(char **paths, char *comand);
void	create_pipes(t_pipex *pipex);
void	ft_exec_comands(t_pipex pipex, char **argv, char **envp);
int		check_heredoc(char *argv, t_pipex *pipex);
void	ft_infile(char **argv, t_pipex *pipex);
void	ft_outfile(char *argv, t_pipex *pipex);
void	here_doc(char *argv, t_pipex *pipex);

//** EXTRA_FNC **

int		ft_strncmp(char *str, char *dst, int numb);
char	*ft_strjoin(char *board, char *buffer);

#endif
