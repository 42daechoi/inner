/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:12:46 by daechoi           #+#    #+#             */
/*   Updated: 2022/05/24 20:08:57 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_pipe
{
    char	*file[2];
	char	**cmd0;
	char	**cmd1;
	char	*path_cmd0;
	char	*path_cmd1;
	char	**path;
}	t_pipe;

int	redirect_in(char *path_cmd);
int	redirect_out(char *path_cmd);

#endif