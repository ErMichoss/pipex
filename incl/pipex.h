/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:05:22 by nicgonza          #+#    #+#             */
/*   Updated: 2024/02/22 15:17:39 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

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
	int		pipe_fd[2]
	int		infile;
	int		outfile;
}			t_pipex;


//** INIT **

int	main(int argc, char *argv[], char *envp[]);

//** ERRORS **

void	ft_error_msg(char *s);

//** GNL **

char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *board, char *buffer);
char		*ft_strdup(char *s1);
char		*ft_new_line(char *board);
char		*ft_line(char *board)
char		*ft_read(int fd, char *board);


//** SPLIT **

char	**ft_empty_split(void);
char	*ft_strdp_custom(const char *s, size_t n);
char	**ft_free_str(char **aux);
int		ft_countc(char const *s, char c);
char	**ft_split(char const *s, char c)

//** FUNCTIONS **

int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
