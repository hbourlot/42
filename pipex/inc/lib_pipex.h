/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:41:09 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/31 10:31:58 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPEX_H
# define LIB_PIPEX_H

# include "../libraries/libft_upd/inc/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define READ 0
# define WRITE 1
# define CMP_OK 0
# define BIN "/bin/"
# define SBIN "/sbin/"
# define UBIN "/usr/bin/"
# define USBIN "/usr/sbin/"
# define ULBIN "/usr/local/bin/"
# define ULSBIN "/usr/local/sbin/"

# define ERROR_ARGV "Invalid argv!\nEx: ./pipex file1 cmd1 cmd2 file2"
# define ERROR_ARGV_B "Invalid argv!\nEx: file1 cmd1 cmd2 cmd3 ... cmdn file2"
# define ERR_PERMISSION_DENIED "Permission denied: "
# define ERR_FILE_NOT_FOUND "No such file or directory: "
# define ERR_INVALID_ARGUMENT "Invalid argument: "
# define ERR_NO_SUCH_FILE "No such file or directory: "
# define ERR_DIRECTORY_NOT_FOUND "not a directory: "

typedef struct cmd
{
	int				out_fd;
	int				in_fd;
	char			**args;
	char			*path;
	char			**envp;
	struct cmd		*next;
}					t_cmd;

typedef struct s_pipe_info
{
	int				pipe_id[2];
	int				prev_fd;
}					t_pipe_info;

typedef struct s_process_info
{
	int				wait;
	int				w_status;
	pid_t			pid;
}					t_process_info;

typedef struct s_env_info
{
	char			*path;
	bool			has_envp;
	bool			has_path;
	bool			is_path_empty;
}					t_env_info;

typedef struct data
{
	bool			here_doc;
	int				argc;
	char			**argv;
	char			**envp;
	int				n_cmd;
	int				error;
	t_cmd			*command;
	t_pipe_info		pipe_info;
	t_process_info	process_info;
	t_env_info		env_info;
}					t_data;

//? -- CLOSE --
void				error(char *msg, int exit_val);
void				clear_all(t_cmd **command);
void				error_execve(t_data *data, t_cmd *command);
void				ft_close(int exit_code, t_data *data, char *msg);

//? -- PIPEX --
int					pipex(t_data *data);

//? -- Parsing --
char				*get_path(char *argv, t_env_info *info);
char				**get_args(char *argv);
void				parsing_envp(t_data *data);
void				init_s_envp(t_data *data);
void				init_data(t_data *data, int argc, char *argv[],
						char *envp[]);
void				check_file_access(t_data *data, const char *file_name,
						int exit_s);

//? -- command --

void				create_commands(t_data *data);

// ? -- Utils --
int					do_dup2(t_data *data, t_cmd *command);

// ? -- BONUS --
void				here_doc(t_data *data, t_process_info *process,
						t_pipe_info *p);

void				initialize_file_descriptors(t_data *data, t_cmd *head,
						t_cmd *cmd);

#endif

//?			1     2       3        4     5     6
// ! $> ./pipex infile "cat -e" "ls -l" "ls" outfile
//? 		0     1       2        3     4     5

// !	{{"ls", "-l", NULL}, {"cat", "infile", NULL}};
