/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrupt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:41:08 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/18 21:41:09 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	interrupthandler(int a)
{
	a++;
	g_status = 130;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	terminal_init(struct termios *term)
{
	tcgetattr(STDIN_FILENO, term);
	term->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, term);
}

void	ctrl_d(void)
{
	printf("exit\n");
	exit(0);
}
