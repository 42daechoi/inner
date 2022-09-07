/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:57:28 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/12 18:49:58 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_pwd(void)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	printf("%s\n", temp);
	ft_free(temp);
	temp = NULL;
	g_status = 0;
	return (1);
}
