/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicvrlja <nicvrlja@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:32:57 by nicvrlja          #+#    #+#             */
/*   Updated: 2025/04/08 11:48:17 by nicvrlja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *msg)
{
	write(2, "Error\n", 6);
	while (*msg)
	{
		write(2, msg, 1);
		msg++;
	}
	write(2, "\n", 1);
}

void	img_error(char *path)
{
	write(2, "Error\n", 6);
	write(2, "Texture not found: ", 19);
	if (path)
	{
		while (*path)
		{
			write(2, &(*path), 1);
			path++;
		}
	}
}
