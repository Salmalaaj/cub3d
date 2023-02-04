/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 05:03:19 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/04 03:15:10 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_wall(void)
{
	printf("Error!\n1 is missing in the wall :)");
	exit(EXIT_FAILURE);
}

void	error_newline(void)
{
	printf("Error!\nThe map shouldn't be ending by a new line :)");
	exit(EXIT_FAILURE);
}

void	error_colors(void)
{
	printf("Error\nSomething is wrong in colors :)!\n");
	exit(EXIT_FAILURE);
}

void	error_position(void)
{
	printf("Error\nWrong position for a character :)!\n");
	exit(EXIT_FAILURE);
}
