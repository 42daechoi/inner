/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:06:56 by daechoi           #+#    #+#             */
/*   Updated: 2022/11/23 16:31:28 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	print_manual(void)
{
	ft_putstr_fd(" _____ _____ _____ _____ _____ _____ \n", 1);
	ft_putstr_fd("|  Q  |  W  |  E  |  R  |  T  |  Y  |\n", 1);
	ft_putstr_fd("| pos | pos | pos | rot | rot | rot |\n", 1);
	ft_putstr_fd("| z++ | y++ | z-- | x++ | y++ | z++ |\n", 1);
	ft_putstr_fd(" _____ _____ _____ _____ _____ _____ \n", 1);
	ft_putstr_fd("|  A  |  S  |  D  |  F  |  G  |  H  |\n", 1);
	ft_putstr_fd("| pos | pos | pos | rot | rot | rot |\n", 1);
	ft_putstr_fd("| x-- | y-- | x++ | x-- | y-- | z-- |\n", 1);
	ft_putstr_fd("|_____ _____ _____ _____ _____ _____|\n\n\n", 1);
	ft_putstr_fd(" _______ _______ _______            __________________ \n", 1);
	ft_putstr_fd("|   -   |   +   |   l   |          |     space bar    |\n", 1);
	ft_putstr_fd("| size  | size  |select |          |   select camera  |\n", 1);
	ft_putstr_fd("|   --  |   ++  | light |          |__________________|\n", 1);
	ft_putstr_fd("|_______ _______ _______|          | mouse left button|\n", 1);
	ft_putstr_fd("                                   |   select object  |\n", 1);
	ft_putstr_fd("Defualt selected object is camera. |__________________|\n", 1);
}
